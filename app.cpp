#include"check.h"
#include"class.h"
#include<ctime>
using namespace std;
/*
CODE DEVELOPED BY:SAIKRISHNA S
Contributions Made by:UTSAV DEEP
LAST DATE MODIFIED:07:05:2020    17:45
TOPIC:CREATING A MONTHLY CALENDAR
GROUP ID:1006
PROGRAMME:CBS1002
*/


/*to know that on which day the first day falls on 
 if Jan 1 is sunday then Feb 1 will be 3 days ahead of that
 */
int Calender::firstDayOfMonth[12]= { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
//Defining static members outside the class
/*
 USE OF BOTH MEMBER AND NONMEMBER FUNCTIONS ARE DONE
 TO DIFFERENTIATE THEM MEMBER FUNCTIONS ARE DEFINED AS INLINE
*/
inline int Calender::dayNumber(int day,int month,int year){

     year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + Calender::firstDayOfMonth[month-1] + day) % 7;
    //RETURNS THE DAYNUMBER OF CORRESSPONDING WEEK's  DAY
                                                                      //FOR EXAMPLE:
                                                                       /*
                                                                          0:SUNDAY
                                                                          1:MONDAY
                                                                          2:TUESDAY
                                                                          3:WEDNESDAY AND SO ON...
                                                                                                        */

}
inline char* Calender::getMonthName(int monthNumber){

     return (months[monthNumber]);

}//RETURNS THE PARTICULAR MONTH NAME IN THE FORM OF A STRING

inline int Calender:: numberOfDays(int monthNumber,int year){

    /*
    THIS FUNCTION IS USED TO RETURN THE NUMBER OF DAYS IN A PARTICULAR MONTH
    THAT HAS SPECIFIC RANGE
    FOR NON-LEAP YEAR:28<=NUMBEROFDAYS<=31
    FOR LEAP YEAR:29<=NUMBEROFDAYS<=31
    */

        switch(monthNumber){
        
        case 1:
            return (31);
            break;
        case 2:
            if (isLeap(year)==true)
            return (29);
        else
            return (28);

            break;
        case 3:
            return (31);
            break;
        case 4:
            return (30);
            break;
        case 5:
            return (31);
            break;
        case 6:
            return (30);
            break;
        case 7:
            return (31);
            break;
        case 8:
            return (31);
            break;
        case 9:
            return (30);
            break;
        case 10:
            return (31);
            break;
        case 11:
            return (30);
            break;
        case 12:
            return (31);
        break;
            default:cout<<"THIS IS A WRONG ENTRY. PLEASE ENTER A VALID INPUT"<<endl;
        }

}
inline void Calender:: printCalendar(int year,int month){
/*PRINTS A CALENDAR FOR A GIVEN MONTH AND YEAR*/
    cout<<" **********************Calendar - "<< year<<"*****************************"<<endl;
    int days;
    int current = dayNumber (1, month, year);
    days = numberOfDays (month, year);
    cout<<"\n------------"<<getMonthName(month)<<"--------------\n"<<endl;
    cout<<"  SUN  MON  TUE  WED  THU  FRI  SAT\n"<<endl;
     // Prints appropriate spaces
     int k;
     for (k = 0; k < current; k++)
            cout<<"     ";
     for (int j = 1; j <= days; j++)
        {printf("%5d", j);
         if (++k > 6){
                 k = 0;
                cout<<endl;
            }
        }

        if (k)
            cout<<"\n";//Coming to the newline

        current = k;

    return;

}
void ChooseBground(){

    char choice;
    cout<<"ENTER A CHOICE TO CHANGE THE BACKGROUND COLOR FROM 1-8 (BOTH INCLUSIVE)"<<endl;
    cin>>choice;
    switch(choice){
     case '0':
        system("Color 0F");
        break;
    case '1':
        system("Color 1F");
        break;
    case '2':
        system("Color 2F");
        break;
    case '3':
        system("Color 3F");
        break;
    case '4':
        system("Color 4F");
        break;
    case '5':
        system("Color 5F");
        break;
    case '6':
        system("Color 6F");
        break;
    case '7':
        system("Color 7F");
        break;
    case '8':
        system("Color 8F");
        break;


        default:system("Color FF");

    }


}
void Output(){//THIS FUNCTION SHOWS THE OUTPUT DISPLAY FORMAT OR SIMPLY WHAT IS GOING TO BE SHOWN IN THE CONSOLE WINDOW

    int year,month;
    cout<<"                  WELCOME  "<<endl;
    cout<<"             ENTER ANY PARTICULAR YEAR "<<endl;
    cin>>year;
    try{
        //TO ELIMINATE THE EXISTENCE OF THE ZERO YEAR
    
        if((year==0)){
        
            throw "YOU HAVE ENTERED A WRONG ENTRY W.R.T YEAR FORMAT";
        }
        else{
        
             cout<<"please proceed"<<endl;
             cout<<"TO ENTER MONTH PRESS\n1:FOR JAN\n2:FOR FEB\n3:FOR MARCH\n4:FOR APRIL\n5:FOR MAY\n6:FOR JUNE\n7:FOR JULY\n8:AUGUST\n9:SEPTEMBER\n10:FOR OCTOBER\n11:FOR NOVEMBER\n12:FOR DECEMBER\n"<<endl;
             cin>>month;
             Calender obj;
             obj.setYearMonth(month,year);//calling of setYearMonth function
             obj.printCalendar(year,month);//calling of Calendar function
        }

    }
    catch(char *s){
    
        cout<<"WRONG FORMAT OF INPUT\n"<<s<<endl;
    }


    time_t timing;//time function return type is time_t and timing is the parameter passed to this function


    struct tm * ti;//structure member


    time (&timing);


    ti = localtime(&timing);//function which displays the local machine time in the output

    cout << "CURRENT DETAILS: "<< asctime(ti);

}
int main(){
    //TESTING WITH MAIN FUNCTION

    ChooseBground();
    Output();
    return 0;
}