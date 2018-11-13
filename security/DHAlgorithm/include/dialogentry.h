#ifndef DIALOGENTRY_H
#define DIALOGENTRY_H

#include <QDialog>
#define KEY_SIZE 512

namespace Ui {
class DialogEntry;
}

class DialogEntry : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEntry(QWidget *parent = 0);
    ~DialogEntry();

private slots:
    void on_btnCalculate_clicked(bool checked = false);
    void on_btnGenerate_clicked(bool checked = false);
    void on_btnRegenerate_clicked(bool checked = false);
    void on_btnClose_clicked(bool checked = false);
    void on_editPrivateKeyAlice_textChanged();
    void on_editPrivateKeyBob_textChanged();
    void on_editKeyAlice_textChanged();
    void on_editKeyBob_textChanged();

private:
    Ui::DialogEntry *ui;
    QVector<long long int> baseGround;
    QVector<long long int> baseMod;
    bool overflow;
    long long int dhNumber(long long int a, long long int b, long long int P);
    void printMessage();
};

#endif // DIALOGENTRY_H
