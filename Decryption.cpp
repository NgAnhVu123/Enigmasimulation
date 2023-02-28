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
void combie(int a[]){
    string b;
    int v=0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j< 8; j++)
        {
            if(j!=i){
                for (int k = 0; k < 8; k++)
                {
                    if(k!=j&&k!=i){
                        a[v]=i*100+j*10+k;
                        v++;
                    }
                }
            }
        }   
    }
}
int main()
{
    int array[336];
    combie(array);
    int n_rotorf, n_rotorm, n_rotorl,temp_id, dodai, count, en_rotorf, en_rotorm, en_rotorl, var;
    int check=0, max=0;
    char r_O, r_N, r_E, r_U, r_V, r_L, r_F, r_T, r_R;
    char rotorf[26],rotorm[26],rotorl[26];
    
    char sp_rotorf, sp_rotorm, sp_rotorl, temp, esp_rotorf, esp_rotorm, esp_rotorl;
    string str_in, str_out, estr_out;
    //
    cout<<"Nhap doan ma:";
    cin>> str_in;
    for (int j = 0; j < 336; j++)
    {
        for (int q = 0; q < 26; q++)
        {
            for (int w = 0; w < 26; w++)
            {
                for (int e = 0; e < 26; e++)
                {
                    n_rotorf=array[j]/100;
                    lap_rotor(n_rotorf,rotorf,rotor);
                    n_rotorm=(array[j]/10)%10;
                    lap_rotor(n_rotorm,rotorm,rotor);
                    n_rotorl=array[j]%10;
                    lap_rotor(n_rotorl,rotorl,rotor);
                    sp_rotorf=base[q];
                    sp_rotorm=base[w];
                    sp_rotorl=base[e];
                    char base_rotorf [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
                    char base_rotorm [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
                    char base_rotorl [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
                    rotate_motor(sp_rotorf,rotorf,base_rotorf);
                    rotate_motor(sp_rotorm,rotorm,base_rotorm);
                    rotate_motor(sp_rotorl,rotorl,base_rotorl);
                    for (int i = 0; i < str_in.length(); i++)
                    {
                        count=i+1;
                        temp = str_in[i];//B
                        temp_id = check_id(base, temp);//1
                        temp = base_rotorf[temp_id];//B
                        //printf ("Gia tri ra khoi bang cam la: %c \n", temp);
                        temp_id = check_id(rotorf,temp);//22
                        //cout<<temp_id<<endl<<rotorf<<endl;
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
                        temp = rotorm[temp_id];//M
                        //printf ("Gia tri phan hoi rotor 2 la: %c \n", temp);
                        temp_id = check_id(base_rotorm,temp);//12
                        temp = rotorf[temp_id];//O
                        //printf ("Gia tri phan hoi rotor 1 la: %c \n", temp);
                        temp_id = check_id(base_rotorf,temp);//14
                        temp = base[temp_id];//O
                        //printf ("Gia tri hien thi ra la: %c \n ---------------\n", temp);
                        str_out.push_back(temp);
                        rotate_motor_1dv(rotorf);
                        rotate_motor_1dv(base_rotorf);
                        if(((count) % 26)==0) {
                            rotate_motor_1dv(rotorm);
                            rotate_motor_1dv(base_rotorm);
                        }
                        if(((count) % 676)==0) {
                            rotate_motor_1dv(rotorl);
                            rotate_motor_1dv(base_rotorl);
                        }
                    }
                    dodai= str_out.length();
                    var=0;
                    if(str_out[dodai-1]=='E') var++;
                    if(str_out[dodai-2]=='R') var++;
                    if(str_out[dodai-3]=='U') var++;
                    if(str_out[dodai-4]=='T') var++;
                    if(str_out[dodai-5]=='U') var++;
                    if(str_out[dodai-6]=='F') var++;
                    if(str_out[dodai-7]=='E') var++;
                    if(str_out[dodai-8]=='N') var++;
                    if(str_out[dodai-9]=='O') var++;
                    if(str_out[dodai-10]=='E') var++;
                    if(str_out[dodai-11]=='V') var++;
                    if(str_out[dodai-12]=='O') var++;
                    if(str_out[dodai-13]=='L') var++;
                    if(str_out[dodai-14]=='E') var++;
                    if(str_out[dodai-15]=='N') var++;
                    if(str_out[dodai-16]=='O') var++;
                    if(str_out[dodai-3]==str_out[dodai-5]) var++;
                    if(str_out[dodai-1]==str_out[dodai-7]) var++;
                    if(str_out[dodai-1]==str_out[dodai-10]) var++;
                    if(str_out[dodai-1]==str_out[dodai-14]) var++;
                    if(str_out[dodai-9]==str_out[dodai-12]) var++;
                    if(str_out[dodai-12]==str_out[dodai-16]) var++;
                    if (var>=max)
                    {
                        max=var;
                        en_rotorf = n_rotorf;
                        en_rotorm = n_rotorm;
                        en_rotorl = n_rotorl;
                        esp_rotorf = sp_rotorf;
                        esp_rotorm = sp_rotorm;
                        esp_rotorl = sp_rotorl;
                        estr_out=str_out;
                    }
                    str_out.erase();
                }   
            }   
        }      
        cout<<"Running..."<<endl;
    }
    cout<<"Doan ma sau giai ma la:"<<estr_out<<endl;
    cout<<"To hop rotor la:"<<en_rotorf+1<<esp_rotorf<<"-"<<en_rotorm+1<<esp_rotorm<<"-"<<en_rotorl+1<<esp_rotorl<<endl;
    return 0;
}