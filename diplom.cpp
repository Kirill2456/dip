#include "diplom.h"
#include "ui_diplom.h"


//#include ""
diplom::diplom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::diplom)
{
    ui->setupUi(this);
}

diplom::~diplom()
{
    delete ui;
}
void diplom::getParam(QVector<Target> & t)
{

    ship.V = ui->Print_V_ship->value();
    ship.K = ui->Print_angle_ship->value();

    tar.V = ui->Print_V_tar->value();
    tar.K = ui->Print_angle_target->value();
    tar.Dist = ui->Print_dist_tar->value();
    for(int i =0; i < t.count; i++){
         t.at(i).getShipParam(ui->Print_V_ship->value());
         t.at(i).
    }

    t.getTarParam()
}

void diplom::calculate(QVector<Target> & t)
{
    float res = t.calcelation_distance_ship_to_target(tar, &ship, var, j);
    ui->Vivod_Dist->setValue(res);

    res = t.degrees_peleng(tar, &ship, var, j);
    ui->Vivod_Pealing->setValue(res);

    res = t.ku_degrees(&ship, degrees_peleng(tar, &ship, var, j));
    ui->Vivod_Ku->setValue(res);

}

void diplom::on_pushButton_clicked()
{
    getParam();
    calculate();
}

