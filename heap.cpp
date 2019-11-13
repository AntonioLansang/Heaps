
#include "maxheap19.h"

bool heap::isEmpty(){

        if(last==0){
                return true;
        }else
                return false;
}

bool heap::isFull(){

        if(last==SZ){
                return true;
        }else
                return false;
}

heap::heap()
{
        //Dynamically allocating the array to a default size
        Arr=new int[256+1];

        //Setting SZ to size
        SZ=256;


        //Marker for the last input element in the list
        last=0;

}

heap::heap( int n )
{
        //Dynamically allocating array given n
        Arr=new int[n+1];

        //Setting  the size
        SZ=n;

        //Marker for the last input element in the list
        last=0;

}


void heap::printA()
{
        int i;
        for (i = 1; i < last; ++i)
                cout << setw(4) << arr[i] ;
        cout << endl;
}

// start at item last, move it up until
//   heap property is restored
void heap::upheap()
{


        int CurIndex=last;
        int ParIndex=CurIndex/2;
        int Temp=0;
        int TempIndex=0;

        //While the value at your current index is bigger than its parent
        while(Arr[CurIndex]>Arr[ParIndex])
        {

                //Checks if we have reached the top
                //If not put here. ParIndex will go haywire
                if(CurIndex==1)
                {
                        printf("Now at root\n");
                        return;
                }

                //Finds the parent node's index
                ParIndex=CurIndex/2;

                if(Arr[CurIndex]>Arr[ParIndex])
                {
                        //Changing of the VALUES in the indexes
                        Temp=Arr[ParIndex];
                        Arr[ParIndex]=Arr[CurIndex];
                        Arr[CurIndex]=Temp;


                        CurIndex=ParIndex;
                }
                else if(Arr[CurIndex]<Arr[ParIndex])
                {
                        printf("Node at right place\n");
                        return;
                }

        }//End of While loop


}


// start at item 1, move it down until
//   heap property is restored
// ** swap with larger child & repeat
void heap::downheap()
{
        Arr[1]=Arr[last];

}

void heap::add(int x)
{
        bool Decide=isFull();

        if(Decide==true)
        {
                cout << "Sorry. List is full" << endl;
                return;
        }

        Arr[last+1]=x;
        last++;

        upheap();


}

void heap::downheap()
{

        int CurIndex=1;


        //Case for 2 children;
        while(Arr[ParIndex]!=0&&ParIndex<=SZ)
        {
                //Left child is bigger than the right child
                if(Arr[CurIndex*2]>Arr[CurIndex*2+1])
                {
                        Arr[CurIndex]=Arr[CurIndex*2];
                        Arr[CurIndex*2]=Arr[CurIndex*2+1];


                        CurIndex=CurIndex*2;

                }
                //Right Child is bigger than the left child
                else if(Arr[CurIndex*2+1]>Arr[CurIndex])
                {
                }

        }//End of the while loop

}//End of downheap Function

void heap::remove()
{
        Arr[1]=0;
        bool Decide=isEmpty();

        //Empty list
        if(Decide==true)
        {
                cout << "You entered in an empty list" << endl;
                return;
        }

        //One node
        if(last==1)
        {

                cout << "You have only one node" << endl;
                Arr[1]=0;
                last--;
                return;
        }

        last--;

        downheap();


}
