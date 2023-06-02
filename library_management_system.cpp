#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int add_book(string book);//kitap ekle
int delete_book();//kitap sil
int create_book();//kitp olu?tur
int sign_up();//kullanycy ekle
int log_in();//giri? yap
int delete_user();//kullanycy sil
int list_book(int mode);//kitap listeleme
int borrow_book();//kitap talepi
int assign_book();//kitap atama
int library_menu();
int return_book();
int republish();
int get_data(string id);
int kitap_struct_doldur(string kitap_veri);
struct user
{
    string type,id,name,surname,password,school;
};
struct book
{
	string book_name,writer,year,yetki;
};
struct request_struct
{
    string book , isteyen_kisi;
};
book book1;
user user1;

string s2 = "\t\t";
string s3 = "\t\t\t";

int main()
{   main_menu:
    system("cls");
    int secim;
    cout<<s3<<"WELCOME TO LIBRARY SYSTEM" <<endl;

    cout<<s2<<"1-Log In"<<endl<<s2<<"2-Sign Up"<<endl<<s2<<"3-View The Book List";
    secim=getch();

    if(secim=='1')
        log_in();
    else if(secim=='2')
        sign_up();
    else if(secim=='3')
        list_book(0);
    else
    {
        system("cls");
        goto main_menu;
    }

    goto main_menu;

}
int log_in()
{
    fflush(stdin);
    log_in_menu:
    system("cls");
    int secim;
    string id,password;
    cout<<s3<<"LOG IN"<<endl;
    cout<<s2<<"1-admin"<<endl<<s2<<"2-student"<<endl<<s2<<"3-back to main menu";
    secim=getch();
    system("cls");

    if(secim=='1')
    {
        admin:
        cout<<s2<<"enter id:";
        cin>>id;
        cout<<s2<<"enter password:";
        cin>>password;
        int control = get_data(id);

        if(control){
            if(password == user1.password && user1.type == "admin"){
                library_menu();
            }
            else
            {
                invalid_password:
                system("cls");
                cout<<s3<<"invalid password !"<<endl;
                cout<<s2<<"1-try again"<<endl<<s2<<"2-back to top menu";
                secim=getch();

                if(secim=='1')
                {
                    system("cls");
                    goto admin;
                }
                else if(secim=='2')
                {
                    system("cls");
                    goto log_in_menu;
                }
                else
                {
                 goto invalid_password;
                }
            }
        }
        else
        {
            invalid_id:
            system("cls");
                cout<<s3<<"invalid id !"<<endl;
                cout<<s2<<"1-try again"<<endl<<s2<<"2-back to top menu";
                secim=getch();

                if(secim=='1')
                {
                    system("cls");
                    goto admin;
                }
                else if(secim=='2')
                {
                    system("cls");
                    goto log_in_menu;
                }
                else
                {
                 goto invalid_id;
                }

        }


    }
    else if(secim == '2')
    {
        user:
        cout<<s2<<"enter id:";
        cin>>id;
        cout<<s2<<"enter password:";
        cin>>password;
        int control = get_data(id);

        if(control){
            if(password == user1.password && user1.type == "student"){
                library_menu();
            }
            else
            {
                invalid_password1:
                system("cls");
                cout<<s3<<"invalid password !"<<endl;
                cout<<s2<<"1-try again"<<endl<<s2<<"2-back to top menu";
                secim=getch();

                if(secim=='1')
                {
                    system("cls");
                    goto user;
                }
                else if(secim=='2')
                {
                    system("cls");
                    goto log_in_menu;
                }
                else
                {
                 goto invalid_password1;
                }
            }
        }
        else
        {
            invalid_id1:
            system("cls");
                cout<<s3<<"invalid id !"<<endl;
                cout<<s2<<"1-try again"<<endl<<s2<<"2-back to top menu";
                secim=getch();

                if(secim=='1')
                {
                    system("cls");
                    goto user;
                }
                else if(secim=='2')
                {
                    system("cls");
                    goto log_in_menu;
                }
                else
                {
                 goto invalid_id1;
                }

        }


    }

    else if(secim == '3')
    {
        return 0;
    }
    else
    {
        goto log_in_menu;
    }


}
int get_data(string id)
{

    fstream file;
    file.open("users.txt",ios_base::in);
    string veri;
    string control = " ";

    while (true){
        user1.type = "";
        user1.id = "";
        user1.name = "";
        user1.surname = "";
        user1.password = "";
        user1.school = "";
        file>>veri;
        if (control == veri)
        {                                                           //cout<<"son <3"<<endl;
           break;
        }
        control = veri;
        int counter = 0;
        for(char ch : veri)
        {
            if(ch=='/')
            {
                counter++;

                continue;
            }
            switch(counter)
            {
            case 0:
                user1.type.push_back(ch);
                break;
            case 1:
                user1.id.push_back(ch);
                break;
            case 2:
                user1.name.push_back(ch);
                break;
            case 3:
                user1.surname.push_back(ch);
                break;
            case 4:
                user1.password.push_back(ch);
                break;
            case 5:
                user1.school.push_back(ch);
                break;
            }


        }
        if(user1.id == id){
        	file.close();
            return 1;
        }

    }
    file.close();
    return 0;
}
int sign_up()
{
    fstream file;
    sign_up_menu:
    system("cls");
    int secim;
    string type,id,name,surname,school=" ",password;
    cout<<s3<<"SIGN UP"<<endl;
    cout<<s2<<"1-Admin"<<endl<<s2<<"2-Student"<<endl<<s2<<"3-Back to main menu"<<endl;
    secim=getch();//getchde char olarak alinir.

    if(secim=='1')
        type="admin";
    else if(secim=='2')
        type="student";
    else if(secim=='3')
        return 0;
    else
        goto sign_up_menu;
    system("cls");
    cout<<s2<<"enter your ;"<<endl<<s2<<"ID:"; cin>>id;
    cout<<s2<<"Name:" ; cin>>name;
    cout<<s2<<"Surname:" ; cin>>surname;
    cout<<s2<<"Password:" ; cin>>password;
    if(type=="student"){
        cout<<s2<<"School:";
        cin>>school;
    }

    file.open("users.txt",ios_base::app);
    file<<type<<"/"<<id<<"/"<<name<<"/"<<surname<<"/"<<password<<"/"<<school<<endl;
    file.close();
    system("cls");
    cout<<"Dear "<<name<<" "<<surname<<", your registiration is complete "<<endl;
    fflush(stdin);
    system("pause");
}
int library_menu()
{
back_to_library_menu:
system("cls");
string type = user1.type;
cout<<s3<<"   "+user1.name+"  "+user1.surname<<endl;
cout<<s3<<"welcome to library"<<endl;
cout<<s2<<"1-view book list"<<endl<<s2<<"2-borrow a book"<<endl<<s2<<"3-return a book"<<endl<<s2<<"4-delete account"<<endl;

if(type=="admin")
{
	cout<<s2<<"5-confirm request"<<endl<<s2<<"6-republish"<<endl<<s2<<"7-create a book"<<endl<<s2<<"8-add the book"<<endl<<s2<<"9-delete the book"<<endl;
}
cout<<endl<<endl<<s2<<"0-exit"<<endl;
fflush(stdin);
int secim = getch();
if(secim == '1')
{
    fflush(stdin);
	list_book(0);
}
else if(secim == '2')
{
    fflush(stdin);
	borrow_book();
}
else if(secim=='3')
{
    fflush(stdin);
    return_book();

}
else if(secim=='4')
{
    fflush(stdin);
    int sonuc = delete_user();
    if(sonuc == 1)
        return 0;

}
else if(secim=='5' && type=="admin")
{
    fflush(stdin);
    assign_book();
}
else if(secim=='6' && type=="admin")
{
    fflush(stdin);
    republish();
}
else if(secim=='7' && type=="admin")
{
    fflush(stdin);
	create_book();
}
else if(secim=='8' && type=="admin")
{
    fflush(stdin);
    add_book(" ");
}
else if(secim=='9' && type=="admin")
{
    fflush(stdin);
    delete_book();
}
else if(secim=='0')
{
    fflush(stdin);
	return 0;
}

goto back_to_library_menu;
}
int create_book()
{
	int control = 0;
	fflush(stdin);
	back_to_create_book_menu:
	system("cls");
	string book_name,writer,publication_year,yetki,s;

	cout<<s3<<"CREATE A BOOK (dont use space when you enter value)"<<endl<<endl;
	cout<<s2<<"enter the book name:"; getline(cin,book_name);
	cout<<s2<<"enter the writer name:"; getline(cin,writer);
	cout<<s2<<"enter the publication year:"; getline(cin,publication_year);
	who_show:
	system("cls");
	cout<<endl<<s3<<"who will show this book?"<<endl;
	cout<<s2<<"1-admin"<<endl<<s2<<"2-student"<<endl;

	yetki=getch();
	if(yetki=="1")
		yetki = "1";
	else if(yetki == "2")
		yetki = "0";
	else
		goto who_show;

	fstream file;
	file.open("add_the_book.txt",ios_base::app);
	string book= book_name+"/"+writer+"/"+publication_year+"/"+yetki+"\n";
	file<<book;
	file.close();

	successfully:
	system("cls");
	cout<<s2<<"book saved successfully <3"<<endl;

	cout<<s2<<"1-create book"<<endl<<s2<<"2-add this book to library list"<<endl<<s2<<"3-back to top menu"<<endl;

	int secim;
	secim=getch();
	if(secim=='1'){
		control = 1;
		goto back_to_create_book_menu;
	}
	else if(secim=='2')
		add_book(book);
	else if(secim=='3')
		return 0;
	else
		goto successfully;

}
int add_book(string book=" ")
{
	system("cls");
	fstream file;
	if(book != " "){
		file.open("library.txt",ios_base::app);
		file<<book<<endl;
		file.close();
		return 0;
	}
	kitap_listeleme:
	file.open("add_the_book.txt",ios_base::in);
	string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri)
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;

    veri_sayisi = 0;
    system("cls");
    cout<<endl<<s3<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s3<<"ADD BOOK"<<endl;
    for(string book_verisi : list)
    {
    	if(veri_sayisi == toplam_veri_sayisi)
    		break;
    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
    	cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;

	}
	file.close();

	int book_number;
	string choosen_book;
	cout<<s2<<"press 0 for exit"<<endl<<endl<<s2<<"choose the book number for add to library :";
	cin>>book_number;
	if(book_number == 0){
		return 0;
	}
	else if(book_number < 0){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto kitap_listeleme;
	}
	else if(book_number > toplam_veri_sayisi){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto kitap_listeleme;
	}
	else{
		choosen_book = list[book_number-1];
		file.open("library.txt",ios_base::app);
		file<<choosen_book<<endl;
		file.close();


	}
	kayit_sonrasi:
	system("cls");
	cout<<endl<<s2<<"The book saved succesfully"<<endl;
	string add_book_txt_verisi = "";
	for(string book_verisi : list)
		if(book_verisi != choosen_book && book_verisi != ""){
			add_book_txt_verisi += book_verisi + "\n";
		}

	file.open("add_the_book.txt",ios_base::out);
	file<<add_book_txt_verisi;
	file.close();
	cout<<endl<<s2<<"1-continue add book"<<endl<<s2<<"2-back to main menu";
	int secim = getch();
	if(secim=='1')
		goto kitap_listeleme;
	else if(secim=='2')
		return 0;
	else
	{
		goto kayit_sonrasi;
	}
}
int list_book(int mode = 0)
{
	list_of_book:

	string user_type = user1.type;
	if(user_type == "student")
		user_type = "0";
	else
		user_type = "1";

	system("cls");
	cout<<endl<<s2<<"    BOOK LIST"<<endl;
	fstream file;
	file.open("library.txt",ios_base::in);
	string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri || veri == "")
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;
    file.close();

    veri_sayisi = 0;
    for(string book_verisi : list)
    {

    	if(veri_sayisi == toplam_veri_sayisi)
    		break;

    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
    	if(book1.book_name == "")
            continue;

    	if(book1.yetki == "0" && user_type == "0")
    	{
    		cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;
		}
		if(user_type == "1")
		{
			cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;
		}
	}
	if(mode == 0){
		cout<<endl<<s2;
		system("pause");
	}
	else if(mode == 1)
	{
		cout<<endl<<s2<<"press 0 to exit";
		cout<<endl<<s2<<"Choose a book :";
		int book_number;
		cin>>book_number;

		if(book_number == 0){
		return 0;
		}
		else if(book_number < 0){
			cout<<s2<<"Invalid Number !"<<endl;
			cout<<s2<<system("pause");
			goto list_of_book;
		}
		else if(book_number > toplam_veri_sayisi){
			cout<<s2<<"Invalid Number !"<<endl;
			cout<<s2<<system("pause");
			goto list_of_book;
		}
		else
        {
			string choosen_book;

            if(veri_sayisi == 0)
            {
                cout<<s2<<"Invalid Number !"<<endl;
                cout<<s2<<system("pause");
                goto list_of_book;
            }

			choosen_book = list[book_number-1];
			string request_veri = choosen_book + "\\" + user1.id;
			file.open("requests.txt",ios_base::app);
			file<<request_veri<<endl;
			file.close();

			string lib_txt_verisi = "";
			for(string book_verisi : list)
				if(book_verisi != choosen_book && book_verisi != ""){
					lib_txt_verisi += book_verisi + "\n";
				}

			file.open("library.txt",ios_base::out);
			file<<lib_txt_verisi;
			file.close();

			cout<<endl<<s2<<"Book has been request"<<endl;
			cout<<s2;
			system("pause");
		}
	}
}
int borrow_book()
{
	list_book(1);
	return 0;

}
int assign_book()
{
    confirm_book:
    system("cls");
    cout<<endl<<s3<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s3<<"CONFIRM REQUESTS"<<endl;
    fstream file;
    file.open("requests.txt",ios_base::in);
	string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri|| veri == "")
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;
    file.close();

    veri_sayisi = 0;
    string kim_istiyor_id = "";
    string kim_istiyor_name = "";
    string su_anki_kullanici_id = user1.id;
    for(string book_verisi : list)
    {
    	if(veri_sayisi == toplam_veri_sayisi)
    		break;
        if(book_verisi == "")
            break;
    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
    	int counter = 0;
    	for(char ch : book1.yetki)
        {
            if(ch == '\\')
            {
                counter++;
                continue;
            }
            if(counter == 1)
            {
                kim_istiyor_id.push_back(ch);
            }
        }
        get_data(kim_istiyor_id);
        kim_istiyor_name = user1.name;
        get_data(su_anki_kullanici_id);
        cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<s2<<"who is requester:"<<kim_istiyor_name<<endl<<endl;

    }

    int secim;
    cout<<endl<<s2<<"choose the book:";
    cin>>secim;
    string choosen_book = "";
    if(secim == 0){
		return 0;
	}
	else if(secim < 0){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto confirm_book;
	}
	else if(secim > toplam_veri_sayisi){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto confirm_book;
	}
	else
    {
        if(veri_sayisi == 0)
            {
                cout<<s2<<"Invalid Number !"<<endl;
                cout<<s2<<system("pause");
                goto confirm_book;
            }

        for(char ch : list[secim-1]){
            if (ch == '\\')
            {
                break;
            }
            choosen_book.push_back(ch);
        }

	}

    kim_istiyor_id = "";
    kitap_struct_doldur(list[secim-1]);
    	int counter = 0;
    	for(char ch : book1.yetki)
        {
            if(ch == '\\')
            {
                counter++;
                continue;
            }
            if(counter == 1)
            {
                kim_istiyor_id.push_back(ch);
            }
        }

    file.open(kim_istiyor_id+".txt",ios_base::app);
    file<<choosen_book<<endl;
    file.close();

    string yeni_requests_verileri;
    for(string request_veri : list){
        if(request_veri != list[secim-1] && request_veri != "")
            yeni_requests_verileri += request_veri + "\n";
    }
    file.open("requests.txt",ios_base::out);
    file<<yeni_requests_verileri;
    file.close();

    cout<<endl<<s2<<"Succesfully <3"<<endl<<s2;
    system("pause");

}
int kitap_struct_doldur(string book_verisi)
{
    book1.book_name = "";
    book1.writer = "";
    book1.year = "";
    book1.yetki = "";
    int counter = 0;
    for(char ch : book_verisi)
    	{
	    	if(ch=='/')
	        {
	            counter++;
	            continue;
	        }
	        switch(counter)
	        {
	        case 0:
	            book1.book_name.push_back(ch);
	            break;
	        case 1:
	            book1.writer.push_back(ch);
	            break;
	        case 2:
	            book1.year.push_back(ch);
	            break;
	        case 3:
	            book1.yetki.push_back(ch);
	           break;
	        }
    	}
}
int return_book()
{

    return_book_menu:
    system("cls");
    cout<<endl<<s3<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s3<<"RETURN BOOK"<<endl<<endl;

    fstream file;
    file.open(user1.id+".txt",ios_base::in);

    string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri|| veri == "")
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;
    file.close();

    veri_sayisi = 0;

    for(string book_verisi : list)
    {
        if(veri_sayisi == toplam_veri_sayisi)
    		break;
        if(book_verisi == "")
            break;
    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
        cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;

    }
    int secim;
    cout<<endl<<s2<<"choose the book:";
    cin>>secim;
    string choosen_book = list[secim-1];
    if(secim == 0){
		return 0;
	}
	else if(secim < 0){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto return_book_menu;
	}
	else if(secim > toplam_veri_sayisi){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto return_book_menu;
	}
	else
    {
        if(veri_sayisi == 0)
            {
                cout<<s2<<"Invalid Number !"<<endl;
                cout<<s2<<system("pause");
                goto return_book_menu;
            }


        string yeni_user_kitap_verisi = "";
        for(string book_verisi : list)
        {
            if(book_verisi != choosen_book && book_verisi != "")
            {
                yeni_user_kitap_verisi += book_verisi + "\n";
            }
        }
        file.open(user1.id+".txt",ios_base::out);
        file<<yeni_user_kitap_verisi;
        file.close();

        file.open("wait_to_republish.txt",ios_base::app);
        file<<choosen_book<<endl;
        file.close();

    }
    cout<<endl<<s2;
    system("pause");
}
int delete_user()
{
    delete_user_menu:
    system("cls");
    cout<<endl<<s3<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s3<<"DELETE ACCOUNT"<<endl<<endl;
    string yetki = user1.type;
    fstream file;

    if(yetki == "admin")
    {
        file.open("users.txt",ios_base::in);
        string veri;
        string control = " ";
        string list[10000];
        string id,name,surname;
        int toplam_veri_sayisi = 0;
        int veri_sayisi=0;
        while (true)
        {
            file>>veri;
            if (control == veri|| veri == "")
            {
               break;
            }
            control = veri;
            list[veri_sayisi] = veri;
            veri_sayisi++;
            int counter = 0;
            for(char ch : veri)
            {
                if(ch=='/')
                {
                    counter++;
                    continue;
                }
                switch(counter)
                {
                case 1:
                    id.push_back(ch);
                    break;
                case 2:
                    name.push_back(ch);
                    break;
                case 3:
                    surname.push_back(ch);
                    break;
                }
            }
            cout<<endl<<s2<<veri_sayisi<<"-"<<name<<" "<<surname<<" (id : "<<id<<" )";
            id = "";
            name = "";
            surname = "";

        }
        toplam_veri_sayisi = veri_sayisi;
        file.close();

        veri_sayisi = 0;
        int secim;
        cout<<endl<<s2<<"choose the account for delete:";

        cin>>secim;

        if(secim == 0){
            return 0;
        }
        else if(secim < 0){
            cout<<s2<<"Invalid Number !"<<endl;
            cout<<s2<<system("pause");
            goto delete_user_menu;
        }
        else if(secim > toplam_veri_sayisi){
            cout<<s2<<"Invalid Number !"<<endl;
            cout<<s2<<system("pause");
            goto delete_user_menu;
        }
        else
        {
            string account = list[secim-1];
            if(toplam_veri_sayisi == 0)
                {
                    cout<<s2<<"Invalid Number !"<<endl;
                    cout<<s2<<system("pause");
                    goto delete_user_menu;
                }


            string yeni_users_verisi = "";
            for(string account_verisi : list)
            {
                if(account_verisi != account && account_verisi != "")
                {
                    yeni_users_verisi += account_verisi + "\n";
                }
            }
            file.open("users.txt",ios_base::out);
            file<<yeni_users_verisi;
            file.close();
            cout<<endl<<s2<<"Succesfully <3"<<endl<<s2;
            system("pause");

        }

    }
    else
    {
        file.open("users.txt",ios_base::in);
        string veri;
        string control = " ";
        string list[10000];
        string id,name,surname;
        int toplam_veri_sayisi = 0;
        int veri_sayisi=0;
        while (true)
        {
            file>>veri;
            if (control == veri)
            {
               break;
            }
            control = veri;
            list[veri_sayisi] = veri;
            veri_sayisi++;
        }
        file.close();
        cout<<endl<<s2<<"Do you want to delete your account ? "<<endl<<s2<<"1-Yes, delete it"<<endl<<s2<<"2-No"<<endl;
        int secim = getch();
        if(secim=='1')
        {

            string account = user1.type + "/" + user1.id + "/" + user1.name + "/" + user1.surname + "/" + user1.password + "/" + user1.school;
            string yeni_users_verisi = "";
            for(string account_verisi : list)
            {

                if(account_verisi != account && account_verisi != "")
                {
                    yeni_users_verisi += account_verisi + "\n";
                }
            }
            cout<<yeni_users_verisi;
            file.open("users.txt",ios_base::out);
            file<<yeni_users_verisi;
            file.close();
            cout<<endl<<s2<<"Succesfully <3"<<endl<<s2;
            system("pause");
            return 1;
        }
        else if(secim=='2')
        {
            return 0;
        }
        else
        {
          goto delete_user_menu;
        }
    }
}

int republish()
{
    republish_menu:
    system("cls");
    cout<<endl<<s2<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s2<<"REPUBLISH BOOK"<<endl<<endl;
    fstream file;
    file.open("wait_to_republish.txt",ios_base::in);

    string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri|| veri == "")
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;
    file.close();

    veri_sayisi = 0;

    for(string book_verisi : list)
    {
        if(veri_sayisi == toplam_veri_sayisi)
    		break;
        if(book_verisi == "")
            break;
    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
        cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;

    }
    int secim;
    cout<<endl<<s2<<"choose the book for republish:";
    cin>>secim;
    string choosen_book = list[secim-1];
    if(secim == 0){
		return 0;
	}
	else if(secim < 0){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto republish_menu;
	}
	else if(secim > toplam_veri_sayisi){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto republish_menu;
	}
	else
    {
        if(veri_sayisi == 0)
            {
                cout<<s2<<"Invalid Number !"<<endl;
                cout<<s2<<system("pause");
                goto republish_menu;
            }


        string yeni_kitap_verisi = "";
        for(string book_verisi : list)
        {
            if(book_verisi != choosen_book && book_verisi != "")
            {
                yeni_kitap_verisi += book_verisi + "\n";
            }
        }
        file.open("wait_to_republish.txt",ios_base::out);
        file<<yeni_kitap_verisi;
        file.close();

        file.open("library.txt",ios_base::app);
        file<<choosen_book<<endl;
        file.close();
    }

}
int delete_book()
{
    delete_book_menu:
    system("cls");
    cout<<endl<<s3<<"press 0 for exit"<<endl<<endl;
    cout<<endl<<s3<<"DELETE THE BOOK"<<endl<<endl;

    fstream file;
    file.open("library.txt",ios_base::in);

    string veri;
	string control = " ";
	string list[10000];
	int toplam_veri_sayisi = 0;
	int veri_sayisi=0;
	while (true){
        file>>veri;
        if (control == veri|| veri == "")
        {
           break;
        }
        control = veri;
        list[veri_sayisi] = veri;
        veri_sayisi++;
    }
    toplam_veri_sayisi = veri_sayisi;
    file.close();

    veri_sayisi = 0;

    for(string book_verisi : list)
    {
        if(veri_sayisi == toplam_veri_sayisi)
    		break;
        if(book_verisi == "")
            break;
    	veri_sayisi++;
    	kitap_struct_doldur(book_verisi);
        cout<<s3<<veri_sayisi<<endl<<s2<<"---------------"<<endl<<s2<<"book name:"<<book1.book_name<<endl<<s2<<"writer:"<<book1.writer<<endl<<s2<<"publication year:"<<book1.year<<endl<<endl;

    }
    int secim;
    cout<<endl<<s2<<"choose the book:";
    cin>>secim;
    string choosen_book = list[secim-1];
    if(secim == 0){
		return 0;
	}
	else if(secim < 0){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto delete_book_menu;
	}
	else if(secim > toplam_veri_sayisi){
		cout<<s2<<"Invalid Number !"<<endl;
		cout<<s2<<system("pause");
		goto delete_book_menu;
	}
	else
    {
        if(veri_sayisi == 0)
            {
                cout<<s2<<"Invalid Number !"<<endl;
                cout<<s2<<system("pause");
                goto delete_book_menu;
            }


        string yeni_kitap_verisi = "";
        for(string book_verisi : list)
        {
            if(book_verisi != choosen_book && book_verisi != "")
            {
                yeni_kitap_verisi += book_verisi + "\n";
            }
        }
        file.open("library.txt",ios_base::out);
        file<<yeni_kitap_verisi;
        file.close();
    }
    cout<<endl<<s2;
    system("pause");

}
