#ifndef TARGET_H
#define TARGET_H


struct main_target{
 float x[10];
 float y[10];
 float V;
 float K;
 float Dist;
}tar;
struct carrier_ship
{ float x;
 float y;
 float V;
 float K;
 float Dist;
}ship;

class Target
{
    carrier_ship ship;
    main_target tar;
public:
    Target();
    void getTarParam();
    float degrees_peleng(struct main_target* ptar, struct  carrier_ship* pship);
    float calcelation_distance_ship_to_target(struct main_target* ptar, struct  carrier_ship* pship);
    float ku_degrees(struct  carrier_ship* pship, float peling);
    void getting_x (struct main_target ptar);
    void getting_y (struct main_target ptar);
    void change(struct main_target* ptar);

    /////////////////////////////////////////////////////////////////////
    void getting_x_carrier_ship(struct  carrier_ship* pship);

    void getting_y_carrier_ship(struct  carrier_ship* pship);

    void change_carrier_ship(struct  carrier_ship* pship);

};

#endif // TARGET_H
