#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <unistd.h>
#include <sys/utsname.h>

#include "ui_Qt.h"

QString get_os_release_value(const QString& key) {
    QFile file("/etc/os-release");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith(key + "=")) {
                QString value = line.section('=', 1);
                // Strip out wrapping quotes if they exist in the file
                if (value.startsWith('"') || value.startsWith('\'')) {
                    value = value.mid(1, value.length() - 2);
                }
                return value;
            }
        }
    }
    return "";
}

bool is_dark_theme() {
    QString home = qgetenv("HOME");
    QFile file(home + "/.config/kdeglobals");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains("ColorScheme=Dark") || line.contains("dark") || line.contains("Dark")) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();
    Ui::MainWindow ui;
    ui.setupUi(window);

    struct utsname buffer;
    QString kernel = (uname(&buffer) == 0) ? buffer.release : "Unknown Kernel";

    QString prettyName = get_os_release_value("PRETTY_NAME");
    if (prettyName.isEmpty()) prettyName = "EndeavourOS Linux";

    QString docUrl = get_os_release_value("DOCUMENTATION_URL");
    if (docUrl.isEmpty()) docUrl = "https://endeavouros.com";

        QString theme = is_dark_theme() ? "dark" : "light";
    QString logoPath = QString("/usr/share/pixmaps/endeavouros-logo-text-%1.svg").arg(theme);
    if (!QFile::exists(logoPath)) {
        logoPath = QString("/usr/share/pixmaps/endeavouros-logo-text-%1.png").arg(theme);
    }

    QPixmap logo(logoPath);
    if (!logo.isNull() && ui.label) {
        ui.label->setPixmap(logo.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    if (ui.label_2) ui.label_2->setText("<b>Name:</b> " + prettyName + " GNU/Linux");
    if (ui.label_3) ui.label_3->setText("<b>Kernel:</b> " + kernel);

    if (ui.label_4) {
        ui.label_4->setText("<b>Documentation:</b> <a href='" + docUrl + "'>" + docUrl + "</a>");
        ui.label_4->setOpenExternalLinks(true);
    }
    if (ui.label_5) {
        ui.label_5->setText("<b>License:</b> <a href='https://www.gnu.org/licenses/gpl-3.0.html'>GNU GPLv3</a>");
        ui.label_5->setOpenExternalLinks(true);
    }

    if (ui.okButton) {
        QObject::connect(ui.okButton, &QPushButton::clicked, window, &QMainWindow::close);
    }

    window->setWindowTitle("About GNU/Linux");
    window->show();

    return app.exec();
}
