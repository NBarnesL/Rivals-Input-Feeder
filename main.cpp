#include <windows.h>
#include<iostream>
#include<string>
#include <fstream>
#include "basicact.h"
#include "utility.h"




using std::string;

char up='W';
char down='S';
char left='A';
char right='D';

char attack='U';
char special='I';
char strong='P';
char dodge='O';
bool autorun=true;  //run/walk toggle set to SHIFT


void setup(std::ofstream& outfile, INPUT &ip, std::ifstream &infile);
void menu(int& sel, int &specialActions);
void execute(INPUT &ip, int sel, std::ofstream& outfile);


void initializecontrols(std::ofstream& outfile);

void nspec(INPUT &ip);
void dspec(INPUT &ip);
void uspec(INPUT &ip);
void sspecLeft(INPUT &ip);
void sspecRight(INPUT &ip);

void dstrong(INPUT &ip);
void ustrong(INPUT &ip);
void fstrongRight(INPUT &ip);
void fstrongLeft(INPUT &ip);
void nstrong(INPUT &ip);

void dtilt(INPUT &ip);
void utilt(INPUT &ip);
void ftiltRight(INPUT &ip);
void ftiltLeft(INPUT &ip);
void jab(INPUT &ip);


void runupdtiltLEFT(INPUT &ip);
void runupdtiltRIGHT(INPUT &ip);
void crazydashdancing(INPUT &ip);
void dodgespam(INPUT &ip);
void dodgespam_withDI(INPUT &ip);

void hold_control(INPUT &IP);
void LeftClick ( );
string GetActiveWindowTitle();


int main()
{
// This structure will be used to create the keyboard
// input event.
INPUT ip;
int sel = -1;
std::ifstream infile;
std::ofstream outfile;
int specialActions = 0;

setup(outfile, ip, infile);

while (sel!=99)
{

menu(sel, specialActions);
execute(ip, sel, outfile);



}

// Exit normally
return 0;
}
// ----------------------------------------------------------------------------------
void setup(std::ofstream& outfile, INPUT &ip, std::ifstream &infile)
{
infile.open("input.dat");

// Set up a generic keyboard event.
ip.type = INPUT_KEYBOARD;
ip.ki.wScan = 0; // hardware scan code for key
ip.ki.time = 0;
ip.ki.dwExtraInfo = 0;


if(!infile){
    outfile.open("input.dat");
    outfile<<'U'<<std::endl<<'P'<<std::endl<<'I'<<std::endl<<'O'<<std::endl<<'W'<<std::endl<<'S'<<std::endl<<'A'<<std::endl<<'D';
    outfile.close();
    }

    infile>>attack>>strong>>special>>dodge>>up>>down>>left>>right;
    infile.close();


}

void menu(int& sel, int &specialActions)
{
system("CLS");
sel=-1;

std::cout<<"Inputs: \nup: "<<up<<"\ndown: "<<down<<"\nleft: "<<left<<"\nright: "<<right<<std::endl;
std::cout<<"\nattack: "<<attack<<"\nspecial: "<<special<<"\nstrong: "<<strong<<"\ndodge: "<<dodge;
if (specialActions==0)
{

    std::cout<<"\n\nPlease give your selection: \n0. Initialize Controls\n";
    std::cout<<"\nSpecial Moves: \n1. nspecial\n2. dspecial\n3. uspecial\n4. side special left\n5. side special right\n";
    std::cout<<"\nAttacks: \n6. jab\n7. dtilt\n8. utilt\n9. ftilt left\n10. ftilt right\n";
    std::cout<<"\nStrongs: \n11. nstrong\n12. dstrong\n13. ustrong\n14. fstrong left\n15. fstrong right\n";
    std::cout<<"\n16. >> Special Actions";
    std::cout<<"\n\n\n99. Exit\n";

}
else
{
    std::cout<<"\n\nPlease give your selection: \n69. frame perfect dashdancing\n";
    std::cout<<"50. Run up dtilt (left)\n51. Run up dtilt (right)\n";
    std::cout<<"74. dodgespam\n75. dodgespam with DI (in testing)\n";
    std::cout<<"\n16. << Basic Actions";
    std::cout<<"\n\n\n99. Exit\n";

}




std::cin >> sel;
while(std::cin.fail()) {
    std::cout << "Invalid Input" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> sel;
}
if (sel==16)
{
    if (specialActions==0)
        specialActions=1;
    else
        specialActions=0;

    menu(sel, specialActions);

}



}


void execute(INPUT &ip, int sel, std::ofstream& outfile)
{
    string rivalCheck="";



    if (sel>=1&&sel != 99)
    {
        /*
// Pause for 5 seconds.
std::cout<<"Begin in 5...\n";
    Sleep(1000);
std::cout<<"Begin in 4...\n";
    Sleep(1000);
    */
std:: cout<<"Begin in 3...\n";
    Sleep(1000);
std::cout<<"Begin in 2...\n";
    Sleep(1000);
std:: cout<<"Begin in 1...\n";
    Sleep(1000);

    }


if(sel==0)
initializecontrols(outfile);


else if (sel == 99)
    exit(0);

if (sel!=0&&sel!=99)
{
while(1)
{
rivalCheck=GetActiveWindowTitle();

    switch(sel)
    {
        case 1 :
            if (rivalCheck=="Rivals of Aether")
            nspec(ip);
            break;
        case 2 :
            if (rivalCheck=="Rivals of Aether")
            dspec(ip);
            break;
        case 3 :
            if (rivalCheck=="Rivals of Aether")
            uspec(ip);
            break;
        case 4 :
            if (rivalCheck=="Rivals of Aether")
            sspecLeft(ip);
            break;
        case 5 :
            if (rivalCheck=="Rivals of Aether")
            sspecRight(ip);
            break;
        case 6 :
            if (rivalCheck=="Icons: Combat Arena")
            jab(ip);
            break;
        case 7 :
            if (rivalCheck=="Rivals of Aether")
            dtilt(ip);
            break;
        case 8 :
            if (rivalCheck=="Rivals of Aether")
            utilt(ip);
            break;
        case 9 :
            if (rivalCheck=="Rivals of Aether")
            ftiltLeft(ip);
            break;
        case 10 :
            if (rivalCheck=="Rivals of Aether")
            ftiltRight(ip);
            break;
        case 11 :
            if (rivalCheck=="Rivals of Aether")
            nstrong(ip);
            break;
        case 12 :
            if (rivalCheck=="Rivals of Aether")
            dstrong(ip);
            break;
        case 13 :
            if (rivalCheck=="Rivals of Aether")
            ustrong(ip);
            break;
        case 14 :
            if (rivalCheck=="Rivals of Aether")
            fstrongLeft(ip);
            break;
        case 15 :
            if (rivalCheck=="Rivals of Aether")
            fstrongRight(ip);
            break;
        case 50 :
            if (rivalCheck=="Rivals of Aether")
            runupdtiltLEFT(ip);
            break;
        case 51 :
            if (rivalCheck=="Rivals of Aether")
            runupdtiltRIGHT(ip);
            break;
        case 69 :
            if (rivalCheck=="Rivals of Aether")
            crazydashdancing(ip);
            break;
        case 74 :
            if (rivalCheck=="Rivals of Aether")
            dodgespam(ip);
            break;
        case 75 :
            if (rivalCheck=="Rivals of Aether")
            dodgespam_withDI(ip);
            break;
        default :
            std::cout<<"Invalid Selection.\n\n";
            break;
    }

 if (GetAsyncKeyState(VK_ESCAPE)){ ///used to stop the loop
    system("CLS");
    break;

    }
}
}
}










//-----------------------------------------

void initializecontrols(std::ofstream& outfile)
{

std::cout<<"Enter the attack key: ";
std::cin>>attack;
if (islower(attack)){
attack=toupper(attack);
}
std::cout<<"\nEnter the special key: ";
std::cin>>special;
if (islower(special)){
special=toupper(special);
}
std::cout<<"\nEnter the strong key: ";
std::cin>>strong;
if (islower(strong)){
strong=toupper(strong);
}
std::cout<<"\nEnter the dodge key: ";
std::cin>>dodge;
if (islower(dodge)){
dodge=toupper(dodge);
}
std::cout<<"\nEnter the up key: "; ///to do: prompt user to use a number for a directional key
std::cin>>up;
if (islower(up)){
up=toupper(up);
}
std::cout<<"\nEnter the down key: ";
std::cin>>down;
if (islower(down)){
down=toupper(down);
}
std::cout<<"\nEnter the left key: ";
std::cin>>left;
if (islower(left)){
left=toupper(left);
}
std::cout<<"\nEnter the right key: ";
std::cin>>right;
if (islower(right)){
right=toupper(right);
}
std::cout<<std::endl;
///to do: prompt user whether autorun is enabled

outfile.open("input.dat");
outfile<<attack<<std::endl<<strong<<std::endl<<special<<std::endl<<dodge<<std::endl<<up<<std::endl<<down<<std::endl<<left<<std::endl<<right;
outfile.close();

system("CLS");


}


string GetActiveWindowTitle()
{
 char wnd_title[256];
 HWND hwnd=GetForegroundWindow(); // get handle of currently active window
 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 return wnd_title;
}


void LeftClick ( )
{
INPUT    Input={0};
// left down
Input.type      = INPUT_MOUSE;
Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
::SendInput(1,&Input,sizeof(INPUT));

// left up
::ZeroMemory(&Input,sizeof(INPUT));
Input.type      = INPUT_MOUSE;
Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
::SendInput(1,&Input,sizeof(INPUT));
}





///actions
void runupdtiltLEFT(INPUT &ip)
{
    //std::cout<<"\nRun to the left";
    //Run to the left
    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(250);
    //std::cout<<"\nAttack";
    dtilt(ip);

    ip.ki.wVk =left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(1000);


    //std::cout<<"\ntake it back now y'all";
    //return to original position
    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(300);

    ip.ki.wVk =right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(500);


}

void runupdtiltRIGHT(INPUT &ip)
{
    //std::cout<<"\nRun to the left";
    //Run to the left
    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(250);
    //std::cout<<"\nAttack";
    dtilt(ip);

    ip.ki.wVk =right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
    Sleep(1000);


    //std::cout<<"\ntake it back now y'all";
    //return to original position
    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(300);

    ip.ki.wVk =left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(500);



}



void crazydashdancing(INPUT &ip)
{
ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(45);

    ip.ki.wVk =right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(20);

    ip.ki.wVk =left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));


}

void dodgespam(INPUT &ip)
{
    // Press the "DODGE" key
    ip.ki.wVk = dodge;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "DODGE" key
    ip.ki.wVk =dodge;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);



}

void dodgespam_withDI(INPUT &ip)
{
    // Press the "DODGE" key
    ip.ki.wVk = dodge;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "DODGE" key
    ip.ki.wVk =dodge;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);


    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    ip.ki.wVk =left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

     // Press the "DODGE" key
    ip.ki.wVk = dodge;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "DODGE" key
    ip.ki.wVk =dodge;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    ip.ki.wVk =right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);
}

///attacks
void jab(INPUT &ip)
{
     // Press the "attack" key
    ip.ki.wVk = attack;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void dtilt(INPUT &ip)
{
    // Press the "attack" key
    ip.ki.wVk = attack;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "down" key
    ip.ki.wVk =down;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "down" key
    ip.ki.wVk = down;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void utilt(INPUT &ip)
{
    // Press the "attack" key
    ip.ki.wVk = attack;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "up" key
    ip.ki.wVk =up;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "up" key
    ip.ki.wVk = up;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void ftiltRight(INPUT &ip)
{
    if (autorun==true){
        //Press the Shift Key
        ip.ki.wVk = VK_SHIFT;
        ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    if (autorun==true)
    {
            //release the shift key
            ip.ki.wVk =VK_SHIFT;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
    }
}

void ftiltLeft(INPUT &ip)
{
    if (autorun==true){
    //Press the Shift Key
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(200);

    // Release the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "attack" key
    ip.ki.wVk =attack;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(100);

    if (autorun==true){
    //release the shift key
    ip.ki.wVk =VK_SHIFT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    }
}



///specials
void nspec(INPUT &ip)
{
     // Press the "special" key
    ip.ki.wVk = special;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void dspec(INPUT &ip)
{
    // Press the "special" key
    ip.ki.wVk = special;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "down" key
    ip.ki.wVk =down;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "down" key
    ip.ki.wVk = down;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(50);

}

void uspec(INPUT &ip)
{
    // Press the "special" key
    ip.ki.wVk = special;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "up" key
    ip.ki.wVk =up;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "up" key
    ip.ki.wVk = up;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void sspecRight(INPUT &ip)
{
    if (autorun==true){
        //Press the Shift Key
        ip.ki.wVk = VK_SHIFT;
        ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    if (autorun==true)
    {
            //release the shift key
            ip.ki.wVk =VK_SHIFT;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
    }
}

void sspecLeft(INPUT &ip)
{
    if (autorun==true){
    //Press the Shift Key
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(200);

    // Release the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "special" key
    ip.ki.wVk =special;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(100);

    if (autorun==true){
    //release the shift key
    ip.ki.wVk =VK_SHIFT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    }
}






///strongs
void nstrong(INPUT &ip)
{
     // Press the "strong" key
    ip.ki.wVk = strong;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    // Release the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void dstrong(INPUT &ip)
{
    // Press the "strong" key
    ip.ki.wVk = strong;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "down" key
    ip.ki.wVk =down;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "down" key
    ip.ki.wVk = down;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void ustrong(INPUT &ip)
{
    // Press the "strong" key
    ip.ki.wVk = strong;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "up" key
    ip.ki.wVk =up;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "up" key
    ip.ki.wVk = up;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

}

void fstrongRight(INPUT &ip)
{
    if (autorun==true){
        //Press the Shift Key
        ip.ki.wVk = VK_SHIFT;
        ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

    // Press the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);

    // Release the "right" key
    ip.ki.wVk = right;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

    // Release the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
            Sleep(100);

    if (autorun==true)
    {
            //release the shift key
            ip.ki.wVk =VK_SHIFT;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
    }
}

void fstrongLeft(INPUT &ip)
{
    if (autorun==true){
    //Press the Shift Key
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    }

    // Press the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(200);

    // Release the "left" key
    ip.ki.wVk = left;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "strong" key
    ip.ki.wVk =strong;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(100);

    if (autorun==true){
    //release the shift key
    ip.ki.wVk =VK_SHIFT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    }
}





