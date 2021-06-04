#ifndef CIFRAR_WINDOW_H
#define CIFRAR_WINDOW_H

#include <QDialog>
#include <model_email.h>

namespace Ui {
class Cifrar_Window;
}

class Cifrar_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Cifrar_Window(QWidget *parent = nullptr);
    ~Cifrar_Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cifrar_Window *ui;
};

#endif // CIFRAR_WINDOW_H
