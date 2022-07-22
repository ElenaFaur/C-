#include<iostream>
#include<string>

using namespace std;

class Zombie
{
    private:
        string intension,behaviour,attackTechnique,eatingHabits;
    public:
        void attack()
        {
            cout<<"A Zombie has attacked\n";
        }
};
class ArmyMan
{
    private:
        string uniform,weapon,intension,attackTechnique;
    public:
        void attack()
        {
            cout<<"An Army man has attacked\n";
        }  
        void chooseWeapon()
        {
            cout<<"Army man is choosing a weapon\n";
        }
};
class Bullet
{
    public:
        string color;
        unsigned int size,imageSprite[5120],speed;
        double coordinates;

        void loadBullet()
        {
            cout<<"Bullet has been loaded\n";
        }
        void fireBullet()
        {
            cout<<"Bullet has been fired\n";
        }
};
int main(void)
{
    Zombie zombieObj;
    ArmyMan armymanObj;
    Bullet bulletObj[100];

    cout<<"***********************************\n";
    cout<<"Loading Zombie application\n";
    cout<<"***********************************\n";

    cout<<"sizeof_zombieObj= "<<sizeof(zombieObj)<<" bytes\n"<<
    "sizeof_armymanObj= "<<sizeof(armymanObj)<<" bytes\n"<<
    "sizeof_bulletObj= "<<sizeof(bulletObj)<<" bytes\n";
    return 0;
}