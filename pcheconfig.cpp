#include "pcheconfig.h"
#include "ui_pcheconfig.h"


PCHEConfig::PCHEConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCHEConfig)
{
    ui->setupUi(this);

    QFile file(":/config.csv");
    if (!file.open(QFile::ReadOnly | QIODevice::Text)){
        qDebug() << file.errorString();
    }

    QStringList channelsList;
    QString line = file.readLine();
    channelsList = line.split(';');

    ui->tWIn1->setValue(channelsList[1].toInt());
    ui->tWIn2->setValue(channelsList[2].toInt());
    ui->tWOut1->setValue(channelsList[3].toInt());
    ui->tWOut2->setValue(channelsList[4].toInt());
    ui->tAirIn->setValue(channelsList[5].toInt());
    ui->tAirOut->setValue(channelsList[6].toInt());
    ui->pWIn->setValue(channelsList[7].toInt());
    ui->pWOut->setValue(channelsList[8].toInt());
    ui->pAirIn->setValue(channelsList[9].toInt());
    ui->pAirOut->setValue(channelsList[10].toInt());
    ui->flowRate->setValue(channelsList[11].toInt());
    ui->tAmb->setValue(channelsList[12].toInt());
    ui->diffP->setValue(channelsList[13].toInt());

    line = file.readLine();
    QStringList parameters = line.split(';');
    ui->nbChannels->setValue(parameters[0].toInt());
    ui->wThick->setValue(parameters[1].toDouble()*1000);
    ui->chWidth->setValue(parameters[2].toDouble()*1000);
    ui->chHeight->setValue(parameters[3].toDouble()*1000);
    ui->lBox->setValue(parameters[4].toDouble()*1000);
    ui->nbZigZag->setValue(parameters[5].toInt());
    ui->angle->setValue(parameters[6].toDouble());
    ui->massFlowWater->setValue(parameters[7].toDouble());
    ui->timeInterval->setValue(parameters[8].toDouble());

    line = file.readLine();
    QStringList errors = line.split(';');
    ui->tWIn1Error->setValue(errors[0].toDouble());
    ui->tWIn2Error->setValue(errors[1].toDouble());
    ui->tWOut1Error->setValue(errors[2].toDouble());
    ui->tWOut2Error->setValue(errors[3].toDouble());
    ui->tAirInError->setValue(errors[4].toDouble());
    ui->tAirOutError->setValue(errors[5].toDouble());
    ui->pWInError->setValue(errors[6].toDouble());
    ui->pWOutError->setValue(errors[7].toDouble());
    ui->pAirInError->setValue(errors[8].toDouble());
    ui->pAirOutError->setValue(errors[9].toDouble());
    ui->flowRateError->setValue(errors[10].toDouble());
    ui->tAmbError->setValue(errors[11].toDouble());
    ui->diffPError->setValue(errors[12].toDouble());

    file.close();

}

PCHEConfig::~PCHEConfig()
{
    delete ui;
}

void PCHEConfig::on_buttonBox_accepted()
{
    QFile file(":/config.csv");
    if (!file.open(QFile::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        qDebug() << file.errorString();
    }
    QTextStream out(&file);
    out << 0 << ";"
        << ui->tWIn1->value() << ";"
        << ui->tWIn2->value() << ";"
        << ui->tWOut1->value() << ";"
        << ui->tWOut2->value() << ";"
        << ui->tAirIn->value() << ";"
        << ui->tAirOut->value() << ";"
        << ui->pWIn->value() << ";"
        << ui->pWOut->value() << ";"
        << ui->pAirIn->value() << ";"
        << ui->pAirOut->value() << ";"
        << ui->flowRate->value() << ";"
        << ui->tAmb->value() << ";"
        << ui->diffP->value() << ";\n"

        << ui->nbChannels->value() << ";"
        << ui->wThick->value()/1000 << ";"
        << ui->chWidth->value()/1000 << ";"
        << ui->chHeight->value()/1000 << ";"
        << ui->lBox->value()/1000 << ";"
        << ui->nbZigZag->value() << ";"
        << ui->angle->value() << ";"
        << ui->massFlowWater->value() << ";"
        << ui->timeInterval->value() << ";\n"

        << ui->tWIn1Error->value() << ";"
        << ui->tWIn2Error->value() << ";"
        << ui->tWOut1Error->value() << ";"
        << ui->tWOut2Error->value() << ";"
        << ui->tAirInError->value() << ";"
        << ui->tAirOutError->value() << ";"
        << ui->pWInError->value() << ";"
        << ui->pWOutError->value() << ";"
        << ui->pAirInError->value() << ";"
        << ui->pAirOutError->value() << ";"
        << ui->flowRateError->value() << ";"
        << ui->tAmbError->value() << ";"
        << ui->diffPError->value() << ";";

    file.close();


    emit sendSignal();
}
