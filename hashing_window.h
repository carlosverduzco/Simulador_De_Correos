#ifndef HASHING_WINDOW_H
#define HASHING_WINDOW_H

#include <QDialog>
#include <Tabladedispersion.h>
#include <model_email.h>

namespace Ui {
class Hashing_Window;
}

class Hashing_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Hashing_Window(QWidget *parent = nullptr);
    ~Hashing_Window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Hashing_Window *ui;
    TablaDeDispersion hash;
};

#endif // HASHING_WINDOW_H
