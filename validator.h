#ifndef VALIDATOR_H
	#define VALIDATOR_H
	
	#include "movement.h"

    bool validateMove (int matrix[9][9], int i, int j, int maxMove = 0)
    {
        int choice = makeSafeChoice(matrix, i, j);
		bool capture = cheeseVerify(matrix, i, j);

        if (capture == true)
            return true;
        if (maxMove >= 1000)
            return false;
        
        switch (choice)
        {
            case 0:
                validateMove(matrix, --i, j, ++maxMove);
                break;
            case 1:
                validateMove(matrix, i, --j, ++maxMove);
                break;
            case 2:
                validateMove(matrix, ++i, j, ++maxMove);
                break;
            case 3:
                validateMove(matrix, i, ++j, ++maxMove);
                break;
        }    

    }

    bool validate(int matrix[9][9], int i, int j)
    {
        return (validateMove(matrix, i, j) == true ) ? true : false;
    }

#endif