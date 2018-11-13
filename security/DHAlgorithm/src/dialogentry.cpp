#include "dialogentry.h"
#include "dialogentry.h"
#include "dialogentry.h"
#include "ui_dialogentry.h"
#include <QtGlobal>
#include <QDateTime>
#include <math.h>

DialogEntry::DialogEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEntry)
{
    ui->setupUi(this);

    qsrand(QDateTime::currentDateTime().toTime_t());
    for (int i = 0; i < KEY_SIZE; i++) {
        baseGround.append(((unsigned int)qrand()) % 16 + 1);
        baseMod.append(((unsigned int)qrand()) % 16 + 1);
    }
    printMessage();
}

DialogEntry::~DialogEntry()
{
    delete ui;
}

void DialogEntry::on_btnCalculate_clicked(bool checked)
{
    Q_UNUSED(checked)

    QString strPrivateKeyAlice = ui->editPrivateKeyAlice->toPlainText();
    QString strPrivateKeyBob = ui->editPrivateKeyBob->toPlainText();

    QString strAlice;
    QString strBob;

    overflow = false;
    for(int i = 0; i < KEY_SIZE; i++) {
        long long int nAlice = (strPrivateKeyAlice[i].toLatin1() - 'A') % 12;
        long long int nBob = (strPrivateKeyBob[i].toLatin1() - 'A') % 12;
        long long int exAlice = dhNumber(baseGround[i], nAlice, baseMod[i]);
        long long int exBob = dhNumber(baseGround[i], nBob, baseMod[i]);

        strAlice +=  'A' + dhNumber(exBob, nAlice, baseMod[i]) % ('Z' - 'A');
        strBob += 'A' + dhNumber(exAlice, nBob, baseMod[i]) % ('Z' - 'A');
    }

    ui->editKeyAlice->setText(strAlice);
    ui->editKeyBob->setText(strBob);
    printMessage();
}

void DialogEntry::on_btnGenerate_clicked(bool checked)
{
    Q_UNUSED(checked)

    QString strPrivateKeyAlice;
    QString strPrivateKeyBob;

    for (int i = 0; i < KEY_SIZE; i++) {
        strPrivateKeyAlice += qrand() % 12 + 'A';
        strPrivateKeyBob += qrand() % 12 + 'A';
    }

    ui->editPrivateKeyAlice->setText(strPrivateKeyAlice);
    ui->editPrivateKeyBob->setText(strPrivateKeyBob);
}

void DialogEntry::on_btnRegenerate_clicked(bool checked)
{
    Q_UNUSED(checked)

    baseGround.clear();
    baseMod.clear();
    for (int i = 0; i < KEY_SIZE; i++) {
        baseGround.append(((unsigned int)qrand()) % 16 + 1);
        baseMod.append(((unsigned int)qrand()) % 16 + 1);
    }

    if (ui->editPrivateKeyAlice->toPlainText().size() >= KEY_SIZE && ui->editPrivateKeyBob->toPlainText().size() >= KEY_SIZE) {
        on_btnCalculate_clicked();
    }
    printMessage();
}

void DialogEntry::on_btnClose_clicked(bool checked)
{
    Q_UNUSED(checked)
    done(0);
}

void DialogEntry::on_editPrivateKeyAlice_textChanged()
{
    printMessage();
}

void DialogEntry::on_editPrivateKeyBob_textChanged()
{
    printMessage();
}

void DialogEntry::on_editKeyAlice_textChanged()
{
    printMessage();
}

void DialogEntry::on_editKeyBob_textChanged()
{
    printMessage();
}

long long int DialogEntry::dhNumber(long long int a, long long int b, long long int P)
{
    if (b == 1) {
        return a;
    }
    double ret;
    if ((ret  = pow(a, b)) == HUGE_VAL) {
        overflow = true;
    }
    return (((long long int)ret) % P);
}

void DialogEntry::printMessage()
{
    if (ui->editPrivateKeyAlice->toPlainText().size() < KEY_SIZE || ui->editPrivateKeyBob->toPlainText().size() < KEY_SIZE) {
        ui->btnCalculate->setEnabled(false);
    } else {
        ui->btnCalculate->setEnabled(true);
    }

    QString strIdentical = ui->editKeyAlice->toPlainText() == ui->editKeyBob->toPlainText() ?
                "identical" : "not identical";

    // for fast check whether modulo data was changed
    unsigned char modulo = ~0;
    for (int i = 0; i < KEY_SIZE; i++) {
        modulo ^= (unsigned char)baseGround[i];
        modulo ^= (unsigned char)baseMod[i];
    }

    ui->labelMessage->setText(QString("Random Base Size of Alice: %1 chars, Random Base Size of Bob: %2 chars, Required Minimum Base Size for both: %3 chars.\nGenerated modulo is: %4, Calculated symetric keys are %5, %6.")
                              .arg(QString::number(ui->editPrivateKeyAlice->toPlainText().size()),
                                   QString::number(ui->editPrivateKeyBob->toPlainText().size()),
                                   QString::number(KEY_SIZE, 10),
                                   QString::number(modulo, 2),
                                   strIdentical,
                                   overflow ? "DETECTED ARITHMETIC OVERFLOW": "Last calculation was without arithmetic overflow"));
}
