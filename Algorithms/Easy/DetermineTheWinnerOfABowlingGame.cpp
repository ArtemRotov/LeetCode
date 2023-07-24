/*
2660. Determine the Winner of a Bowling Game

You are given two 0-indexed integer arrays player1 and player2, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of n turns, and the number of pins in each turn is exactly 10.

Assume a player hit xi pins in the ith turn. The value of the ith turn for the player is:

2xi if the player hit 10 pins in any of the previous two turns.
Otherwise, It is xi.
The score of the player is the sum of the values of their n turns.

Return

1 if the score of player 1 is more than the score of player 2,
2 if the score of player 2 is more than the score of player 1, and
0 in case of a draw.
*/


class Solution {
public:
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) 
    {
        std::pair<int,int> p {0, -10};
        for (int i = 0; i < player1.size(); i++)
        {
            if (p.second == i-1 || p.second == i-2)
                p.first += 2*player1[i];
            else
                p.first += player1[i];
            
            if (player1[i] == 10) p.second = i;
        }

        std::pair<int,int> p2 {0, -10};
        for (int i = 0; i < player2.size(); i++)
        {
            if (p2.second == i-1 || p2.second == i-2)
                p2.first += 2*player2[i];
            else
                p2.first += player2[i];
            
            if (player2[i] == 10) p2.second = i;
        }

        return (p.first > p2.first) ? 1 : (p.first < p2.first) ? 2 : 0;
    }
};
