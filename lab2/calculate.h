#ifndef CALCULATE_H
#define CALCULATE_H

//  class ofrating system is used to calculate the relative skill levels
//  of players in competitor-versus-competitor games
class Rating
{
    public:
        Rating();
        Rating(int ra, int rb, int k);
        
        int getRA();
        int getRB();
        int getK();

        void setRnK(int ra, int rb, int k);

        void calculateR(double scoreA);
    
    private:
        int RA, RB, K;
        double getEA();
        double getEB();
};
#endif