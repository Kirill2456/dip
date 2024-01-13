#ifndef DIPLOM_H
#define DIPLOM_H

#include <QMainWindow>
#include <QVector>
#define PI 3.1415
QT_BEGIN_NAMESPACE
namespace Ui { class diplom; }
QT_END_NAMESPACE

/*struct main_target{
 float x[10]; float y[10];
 float V;
 float K;
 float Dist;
}tar;
struct carrier_ship
{ float x;
 float y; float V;
 float K;
 float Dist;
}ship;
*/

//class Target;
class diplom : public QMainWindow
{
    Q_OBJECT

public:
    diplom(QWidget *parent = nullptr);
    ~diplom();

private slots:
    void on_pushButton_clicked();

private:
    Ui::diplom *ui;
    QVector<Target> t1;
    void getParam(Target &t);
    void calculate(Target &t);
    //carrier_ship ship;
   // main_target tar;
};
#endif // DIPLOM_H
