#include<iostream>
#include<map>
#include<string>

using namespace std;
//Instances of SharedBullet will be the Flyweights
class SharedBullet
{
    private:
        std::string color;
        int size;
    public:
        SharedBullet(const std::string &color=""):color(color){}
        std::string b_color()const{return color;}
};
class UniqueBullet {
public:
    UniqueBullet();
    
private:
    unsigned int speed;
    double coordinates;
};
//FlyweightFactory acts as a factory and cache for SharedBullet flyweight objects
class FlyweightFactory
{
    private:
        std::map<std::string,SharedBullet> sharedBullets;
    public:
        FlyweightFactory():sharedBullets(){}

        SharedBullet& findByName(const std::string& b_color)
        {
            if(sharedBullets.count(b_color)!=0)
            {
                cout<<"Found an existing Bullet Object with color "<<sharedBullets[b_color].b_color()<<"\n";
                return sharedBullets[b_color];
            }
            else
            {
                SharedBullet newSharedBullet(b_color);
                sharedBullets[b_color]=newSharedBullet;
                cout<<"Creating a new Bullet Object with color "<<sharedBullets[b_color].b_color() << "\n";
                return sharedBullets[b_color];
            }
        }
};
//Context maps a unique sharedBullet to their size
class Context
{
    private:
        std::map<int,SharedBullet*>m_bullets;
        FlyweightFactory m_fwfactory;
    public:
        Context():m_bullets(),m_fwfactory(){}
        void addBullet(const std::string& b_color, int size)
        {
            m_bullets[size]=&m_fwfactory.findByName(b_color);
        }
        void sharedBullets()
        {
            for(auto i:m_bullets)
            {
                const int size=i.first;
                const auto sharedBullet=i.second;
                std::cout<<sharedBullet->b_color()<<" bullets are of size "<<size<<"cm"<<std::endl;
            }
        }
};
int main()
{
    Context bulletDb;
    bulletDb.addBullet("black",5);
    bulletDb.addBullet("silver",10);
    bulletDb.addBullet("silver",15);
    bulletDb.sharedBullets();

    return 0;
}