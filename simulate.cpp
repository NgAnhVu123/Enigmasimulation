#include <iostream>

using namespace std;

char rotor [8][26]={
    {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'},
    {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
    {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
    {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
    {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
    {'J','P','G','V','O','U','M','F','Y','Q','B','E','N','H','Z','R','D','K','A','S','X','L','I','C','T','W'},
    {'N','Z','J','H','G','R','C','X','M','Y','S','W','B','O','U','F','A','I','V','L','P','E','K','Q','D','T'},
    {'F','K','Q','H','T','L','X','O','C','B','J','S','P','D','Z','R','A','M','E','W','N','I','U','Y','G','V'}
};

char reflectors[26]={'E','J','M','Z','A','L','Y','X','V','B','W','F','C','R','Q','U','O','N','T','S','P','I','K','H','G','D'};
char base [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void lap_rotor(int hang, char dich[],char f_rotor[][26]){
    for (int i = 0; i < 26; i++)
    {
        dich[i] = f_rotor[hang][i];
    }  
}

void rotate_motor(char check,char array1[],char array2[]){
    char temp1[26];
    char temp2[26];
    int k=0, moc =0;
    for (int i = 0; i < 26; i++)
    {
        if (array2[i]==check) moc=i;
    }
    for (int i = moc; i < 26; i++)
    {
        temp1[k]=array1[i];
        temp2[k]=array2[i];
        k++;
    }
    for (int i = 0; i < moc; i++)
    {
        temp1[k]=array1[i];
        temp2[k]=array2[i];
        k++;
    }
    for (int i = 0; i < 26; i++)
    {
        array1[i]=temp1[i];
        array2[i]=temp2[i];
    }
}
void exchange_plug(string array1,char array2[]){
    int i=0;
    int v,u;
    char temp;
    while (array1[i] != '\0') {
		if (array1[i] == ','||array1[i] == '.') {
			i++;
		}
		else {
            for (int j = 0; j < 26; j++)
            {
                if (array2[j]==array1[i]) v=j;
            }
            for (int k = 0; k < 26; k++)
            {
                if (array2[k]==array1[i+1]) u=k;
            }
            array2[v]=array1[i+1];
            array2[u]=array1[i];
            i=i+2;
		}		
	}
}
void rotate_motor_1dv(char array[]){
    char temp[26];
    temp[0]=array[25];
    for (int i = 0; i < 25; i++)
    {
        temp[i+1]=array[i];
    }
    for (int i = 0; i < 26; i++)
    {
        array[i]=temp[i];
    }
}
int check_id(char f_array[26],char letter){
    for (int i = 0; i < 26; i++)
    {
        if (f_array[i] == letter) return i;
    } 
    return -1;
}
int main()
{
    int v = 1;
    int n_rotorf, n_rotorm, n_rotorl,temp_id;
    char board [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char rotorf[26],rotorm[26],rotorl[26];
    char base_rotorf [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char base_rotorm [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char base_rotorl [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char sp_rotorf, sp_rotorm, sp_rotorl, temp;
    string str_in, str_out, plug;
    cout<<"Rotor thu nhat: ";
    cin>> n_rotorf;
    n_rotorf--;
    lap_rotor(n_rotorf,rotorf,rotor);
    cout<<"Gia tri dat cua rotor thu nhat: ";
    cin>>sp_rotorf;
    rotate_motor(sp_rotorf,rotorf,base_rotorf);
    cout<<"Rotor thu hai: ";
    cin>> n_rotorm;
    n_rotorm--;
    lap_rotor(n_rotorm,rotorm,rotor);
    cout<<"Gia tri dat cua rotor thu hai: ";
    cin>>sp_rotorm;
    rotate_motor(sp_rotorm,rotorm,base_rotorm);
    cout<<"Rotor thu ba: ";
    cin>> n_rotorl;
    n_rotorl--;
    lap_rotor(n_rotorl,rotorl,rotor);
    cout<<"Gia tri dat cua rotor thu ba: ";
    cin>>sp_rotorl;
    rotate_motor(sp_rotorl,rotorl,base_rotorl);
    //
    cout << "Nhap chuoi plugboard (VD: AH,BF,...) ";
    cin >> plug;
    exchange_plug(plug,board);
    cout <<"Chuoi plugboard: "<< board<< endl;
    //
    cout << "Nhap chuoi ky tu muon ma hoa: ";
    cin >>   str_in;
    for (double i = 0; i < str_in.length(); i++)
    {
        temp = str_in[i];//I
        temp_id = check_id(board, temp);//0
        temp = base_rotorf[temp_id];//A
        //printf ("Gia tri ra khoi bang cam la: %c \n", temp);
        temp_id = check_id(rotorf,temp);//20
        temp = base_rotorm[temp_id];//U
        //printf ("Gia tri ra khoi rotor 1 la: %c \n", temp);
        temp_id = check_id(rotorm,temp);//7
        temp = base_rotorl[temp_id];//H
        //printf ("Gia tri ra khoi rotor 2 la: %c \n", temp);
        temp_id = check_id(rotorl,temp);//3
        temp = base[temp_id];//D
        //printf ("Gia tri ra khoi rotor 3 la: %c \n", temp);
        temp_id = check_id(reflectors,temp);//25
        //printf ("Gia tri ra khoi reflector la: %c \n", base[temp_id]);
        temp = rotorl[temp_id];//O
        //printf ("Gia tri phan hoi rotor 3 la: %c \n", temp);
        temp_id = check_id(base_rotorl,temp);//14
        temp = rotorm[temp_id];//M4
        //printf ("Gia tri phan hoi rotor 2 la: %c \n", temp);
        temp_id = check_id(base_rotorm,temp);//12
        temp = rotorf[temp_id];//O
        //printf ("Gia tri phan hoi rotor 1 la: %c \n", temp);
        temp_id = check_id(base_rotorf,temp);//14
        temp = board[temp_id];//O
        //printf ("Gia tri hien thi ra la: %c \n ---------------\n", temp);
        str_out.push_back(temp);
        rotate_motor_1dv(rotorf);
        rotate_motor_1dv(base_rotorf);
        if((v % 26)==0) {
            rotate_motor_1dv(rotorm);
            rotate_motor_1dv(base_rotorm);
        }
        if((v % 676)==0) {
            rotate_motor_1dv(rotorl);
            rotate_motor_1dv(base_rotorl);
        }
        v++;
    }
    cout << str_out<<endl;
    return 0;
}