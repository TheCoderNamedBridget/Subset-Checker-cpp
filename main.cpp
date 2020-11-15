/******************************************************************************

Name: Bridget Naylor
Date: 11/14/2020
Exam 2 Part 2

*******************************************************************************/

#include <iostream>
using namespace std;

bool binarySearch( int list[], int start, int end, int num )
{
    if ( end < start  )//not found
    {
        return false;
    }
    int middle = start + (end - start) / 2;

    if ( num == list[middle] )//found
    {
        return true;
    }
    else if ( num < list[middle] )//less than
    {
        return binarySearch( list, start, middle - 1, num );
    }
    else if ( num > list[middle] )//greater than
    {
        return binarySearch( list, middle + 1, end, num );
    }
}

bool subset( int list1[], int list2[], int sizeList1, int sizeList2 )
{
    bool numFound = true;
    int itr = 0;
    while ( numFound && itr < sizeList2 )
    {
        if ( !binarySearch( list1, 0, sizeList1 - 1, list2[itr] ))
        {
            cout<<"Not a subset"<<endl;
            return false;
        }
        itr++;
    }
    cout<<"Subset"<<endl;
    return true;
}

int main()
{
    //Took input generator from Lab 2
    srand (time(0));
    
    //int n = rand() % 30 + 10;
    int n = 10;
    int missingNumChance;
    int missingNumIndex = 0;
    
    int sortedNums[n];
    int value = 0;
    for ( int i = 0; i < n ; i++ )
    {
        missingNumChance = rand() % 10 ;
        if ( missingNumChance > 8 )//50% chance this i will be a missing number
        {
            value ++;
            sortedNums[i] = value;
        }
        else 
        {
            sortedNums[i] = value;
        }
        
        cout<<"i = "<<i<<" item[i] = "<<sortedNums[i]<<endl;
        value ++;
    }
    // cout<<"found 5 "<<binarySearch( sortedNums, 0, n, 5 );
    // cout<<"found 55 "<<binarySearch( sortedNums, 0, n, 55 );
    //generating second list
    int k = n - (rand() % 10 + 2);
    int unsortedNums[k];
    bool exists;
    for ( int i = 0; i < k ; i++ )
    {
        int randomNum = rand() % n;
        //make sure no values are repeated
        exists = true;
        
        
        while( exists )
        {
            exists = false;
            for ( int r = 0; r < i; r++ )
            {
                if ( randomNum == unsortedNums[r] )
                {
                    randomNum = rand() % n;
                    exists = true;
                }
            }
            
        }
        unsortedNums[i] = randomNum;
        cout<<"I = "<<i<<" unsortedNums[I] = "<<unsortedNums[i]<<endl;
    }
    
    subset( sortedNums, unsortedNums, n, k );
    
    return 0;
}
