#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <ctime>//for decoration purpose only
using namespace std;
//about option1-order
void system_interface();
void print1();
void option1();
void print2();
void print3();
void synopsis();
bool exit_page();

struct Movie
{
    string movie_ID;
    string movie_name;
    string time;
    string directors;
    string language;
    string genre;
    int ranking;
    double price;
    string slot;
};

const int max_movie = 5; //max exist 5 movie only
int array_movie(Movie movies[], const string&);
Movie movies[max_movie];
int num_movie = array_movie(movies, "Movie_information.txt");
void seat(int);
const int column = 10;
const int row = 10;
char seats[max_movie][row][column] = {};
void valid_of_seat(int, string);
void booking();
int num_of_book = 0;
string seat_code(string, char);
void save_into_cart(string, string, string);
void cart(string);

struct Cart
{
    string record_id;
    string record_name;
    string record_seat;
    double record_price;
};

const int max_line_in_cart = 500;
int array_cart(Cart carts[]);
Cart carts[max_line_in_cart];
bool edit_cart();
string delete_id_seat_code(string, string);
void delete_id_seat(string, string);
int line_in_cartfile = array_cart(carts);
// about option2- payment
void print4();
bool payment();
double discount();
double payment_method(double);
string method;
double customer_pay = 0;
double member_discount();
string membership;
//about option3-transaction record
void history_list();
bool history();
//about option4- membership
bool option4();
void membership_interface();
void acc_registration();
void acc_management();
void exit_program();
void clear_screen();

struct User
{
    string id;
    string password;
    string name;
    string nric;
    string email;
    string phone;
    string membership_level;
};

int main() {

    int option;
    bool enter = true;

    while (enter)
    {
        system_interface();
        cin >> option;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// prevent invalid variable type of input 
        switch (option)
        {
        case 1:
        {
            option1();
            enter = true;
            break;
        }
        case 2:
        {
            enter = payment();
            break;
        }
        case 3:
        {
            enter = history();
            break;
        }
        case 4:
        {
            enter = option4();
            break;
        }
        case 5:
        {
            enter = exit_page();
            break;
        }
        default:
        {
            cout << "Invalid input. Please key in the number between \"1\" to \"6\". " << endl;
            enter = true;
        }
        }
    }
    system("pause");
    return 0;
}

void system_interface()
{
    system("cls");// Clear the entire screen 
    cout << "\n\n\n";
    cout << "\t\t =========================================================================================================================================================================" << endl;
    cout << "\t\t||                                                                                                                                                                      ||" << endl;
    cout << "\t\t||                                                                                                                                                                      ||" << endl;
    cout << "\t\t||                        .:::.                         //                                 ____   _____       _____                ____         ____  \t\t\t||" << endl;
    cout << "\t\t||                    .+%@@@@@@@*-                     //                                  |   | /    /       |    |              |    \\       |    |\t\t\t||" << endl;
    cout << "\t\t||     :+#@@@@%*-    *@@+:    .-#@%:                  //                                   |   |/    /        |    |              |     \\      |    |\t\t\t||" << endl;
    cout << "\t\t||    *@@+:..:=#@%: #@#          -@@:                //                                    |   '    /         |    |              |      \\     |    |\t\t\t||" << endl;
    cout << "\t\t||   #@*        -@@-@@.           *@*               //                                     |       /          |    |              |       \\    |    |\t\t\t||" << endl;
    cout << "\t\t||  .@@.         %@+@@.           *@*              //                                      |      /           |    |              |        \\   |    |\t\t\t||" << endl;
    cout << "\t\t||   @@=        :@@:#@#          -@@              //                                       |   ,   \\          |    |              |     __  \\__|    |\t\t\t||" << endl;
    cout << "\t\t||   .%@*:    .+@@=  *@%+:    .-#@%              //                                        |   |\\   \\         |    |________      |    |  \\         |\t\t\t||" << endl;
    cout << "\t\t||    :@@@@@@@@@@@%%%%@@@@@@@@@@@-     .=#%=    //                                         |   | \\   \\        |             |     |    |   \\        |\t\t\t||" << endl;
    cout << "\t\t||   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@.  //                                          |___|  \\___\\       |_____________|     |____|    \\_______|\t\t\t||" << endl;
    cout << "\t\t||  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@  //                                                                                                                        ||" << endl;
    cout << "\t\t||  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.//                                                                                                                         ||" << endl;
    cout << "\t\t||  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\\\\                                                                                                    \t\t\t||" << endl;
    cout << "\t\t||  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. \\\\                                             :+####=.  #  ==      *#: #######  =          =      +.\t\t\t||" << endl;
    cout << "\t\t||  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.  \\\\                                           :#@%+=+*%* @@ #@#:    #@: @@      :@+       .#%    =@%\t\t\t||" << endl;
    cout << "\t\t||  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@.   \\\\                                         .@@+        @@ #@@@%-  #@: @@      :@@#.    =@@%   -@@@#\t\t\t||" << endl;
    cout << "\t\t||   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@.    \\\\                                        =@@.        @@ *@% #@% %@: @@@@@@# :@@@@=  *@@@%  :@@=#@*\t\t\t||" << endl;
    cout << "\t\t||    :*%%@@@@@@@@@@@@@@@@@@@%%*-      .=#%=      \\\\                                       .%@*.       @@ *@#  :#@@@: @@      :@%  @#@@  @%  .@@%  @@+\t\t\t||" << endl;
    cout << "\t\t||                                                 \\\\                                       .*@@####@# @% *@#    :#@- @@      :@%  =@%: +@# .%@*=+++@@=\t\t\t||" << endl;
    cout << "\t\t||                                                  \\\\                                        :+####=. += -+=      :: ####### .++       -+= -+=     :++\t\t\t||" << endl;
    cout << "\t\t||                                                   \\\\                                                                                                                 ||" << endl;
    cout << "\t\t||                                                    \\\\                                                                                                                ||" << endl;
    cout << "\t\t||                                                                                                                                                                      ||" << endl;
    cout << "\t\t||                                                                                                                                                                      ||" << endl;
    cout << "\t\t=========================================================================================================================================================================" << endl;
    cout << "\n\n\n";
    cout << "\t\t\t\t\t ============================== \t ============================= \t\t ==============================" << endl;
    cout << "\t\t\t\t\t || 1 || Order               || \t || 2 || Payment            || \t\t || 3 || Transaction Record  ||" << endl;
    cout << "\t\t\t\t\t ============================== \t ============================= \t\t ==============================" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t\t\t\t ============================== \t ==============================" << endl;
    cout << "\t\t\t\t\t\t\t || 4 || Membership          || \t || 5 || Exit                ||" << endl;
    cout << "\t\t\t\t\t\t\t ============================== \t ==============================" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tOption : ";
}

void print1()
{
    system("cls");
    cout << " ============================================" << endl;
    cout << " || 1 ||  Book Ticket(s)                   ||" << endl;
    cout << " ============================================" << endl;
    cout << " || 2 ||  Cart                             ||" << endl;
    cout << " ============================================" << endl;
    cout << " || 3 ||  Exit                             ||" << endl;
    cout << " ============================================" << endl;
}

void option1()
{
    bool option1 = true;
    int choice, choice1;
    int count = 0;
    char yes_no;
    string line, booking1;

    while (option1)
    {
        print1();// call function

        cout << "Please choose the option that you want to conduct : ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// prevent invalid variable type of input 

        switch (choice)
        {
        case 1:
        {
            bool a = true;
            while (a)
            {
                print2();// call function                      
                array_movie(movies, "Movie_information.txt");// call function

                cout << left;
                cout << setw(12) << "Movie ID" << setw(41) << "Movie Name" << setw(26) << "Time" << setw(31) << "Director(s)" << setw(15) << "Language" << setw(33) << "Genre"
                    << setw(13) << "Ranking" << setw(12) << "Price(RM)" << "Time Available" << endl;

                for (int i = 0; i < 5; i++)
                {
                    cout << setprecision(2) << fixed;
                    cout << setw(12) << movies[i].movie_ID << setw(41) << movies[i].movie_name << setw(26) << movies[i].time << setw(31) << movies[i].directors << setw(15)
                        << movies[i].language << setw(33) << movies[i].genre << setw(13) << movies[i].ranking << setw(12) << movies[i].price << movies[i].slot << endl;
                }
                cout << endl << endl;

                print3();// call function

                cin >> choice1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice1)
                {
                case 1:
                {
                    cout << "\nDo you want to see the synopsis of the movie? (<Y>es / Key in any key to exit) ";
                    cin >> yes_no;

                    if (toupper(yes_no) == 'Y')
                    {
                        synopsis();//call function
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        a = true;
                    }
                    break;
                }
                case 2:
                {
                    booking();//call function
                    a = true;
                    option1 = true;
                    break;
                }
                case 3:
                {
                    // call function
                    a = exit_page();
                    break;
                }
                default:
                {
                    cout << "Invalid input!!! Please key in again." << endl;
                    a = true;
                }
                }
            }
            break;
        }

        case 2:
        {
            system("cls");
            bool b = true;

            while (b)
            {
                cart("cart.txt");// call function              
                b = edit_cart();// call function
            }
            break;
        }

        case 3:
        {
            option1 = exit_page();
            break;
        }

        default:
        {
            cout << "Invalid Input" << endl;
        }
        }
    }
}

bool exit_page()
{
    char exit;

    cout << "Do you want to exit this page? (<Y>es or key in any key for No) ";
    cin >> exit;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (toupper(exit) == 'Y')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void print2()
{
    system("cls");
    cout << "=============================================================================================================" << endl;
    cout << "||    _______________      ______________     _______________             _______________       ______      ||" << endl;
    cout << "||   |               |    |              |   |               |            |              |     |      |     ||" << endl;
    cout << "||   |_____     _____|    |    _____     |   |     _____     |            |   ___________|     |      |     ||" << endl;
    cout << "||         |    |         |   |     |    |   |    |     |    |            |   |                |      |     ||" << endl;
    cout << "||         |    |         |   |     |    |   |    |_____|    |            |   |__________      |      |     ||" << endl;
    cout << "||         |    |         |   |     |    |   |     __________|            |              |     |      |     ||" << endl;
    cout << "||         |    |         |   |     |    |   |    |                       |__________    |     |      |     ||" << endl;
    cout << "||         |    |         |   |     |    |   |    |                                  |   |     |______|     ||" << endl;
    cout << "||         |    |         |   |_____|    |   |    |                       ___________|   |                  ||" << endl;
    cout << "||         |    |         |              |   |    |                       |              |       _____      ||" << endl;
    cout << "||         |____|         |______________|   |____|                       |______________|      |_____|     ||" << endl;
    cout << "||                                                                                                          ||" << endl;
    cout << "=============================================================================================================" << endl;
    cout << "\n\n\n" << endl;
}

void print3()
{
    cout << "\t\t=========================\t\t=========================\t\t=========================" << endl;
    cout << "\t\t|| 1 || Synopsis       ||\t\t|| 2 || Booking        ||\t\t|| 3 || Exit           ||" << endl;
    cout << "\t\t=========================\t\t=========================\t\t=========================" << endl;
    cout << "\t\t\t\t\t\tOption: ";
}

int array_movie(Movie movies[], const string& filename)
{
    int num_movie = 0;
    ifstream movie_file(filename);

    if (movie_file.is_open())
    {
        string line;
        // store the movie information from file and store it in struc in array
        while (getline(movie_file, line) && num_movie < max_movie)
        {
            Movie movie;
            movie.movie_ID = line.substr(0, 11);
            movie.movie_name = line.substr(11, 40);
            movie.time = line.substr(52, 25);
            movie.directors = line.substr(78, 30);
            movie.language = line.substr(109, 15);
            movie.genre = line.substr(125, 33);
            movie.ranking = stoi(line.substr(158, 1));
            movie.price = stod(line.substr(163, 5));
            movie.slot = line.substr(172, 15);
            movies[num_movie] = movie;
            num_movie++;
        }
    }

    else
        cout << "Not recorded found." << endl;

    movie_file.close();

    return num_movie;// in order to know how many movie in file
}

void synopsis() //view synopsis module
{
    string line, synopsis_line, movie_ID;
    int count = 0;
    char continues;
    bool a = true;

    while (a)
    {
        cout << "\nKey in the ID of the movie that you want to see the synopsis : ";
        cin >> movie_ID;

        if (!isalpha(movie_ID[0]) || !isdigit(movie_ID[1]) || !isdigit(movie_ID[2])) //check the format of the movie id first must be alphabet while second and third must be the digit
        {
            cout << "\nInvalid input for movie ID!!! Please key in again.\n" << endl;
            a = true;
        }
        else
        {
            ifstream moviefile("Movie_information.txt");

            if (moviefile.is_open())
            {
                bool found_movie_id = false;

                cout << endl << endl << endl;
                moviefile.seekg(0, ios::beg);  // reset file pointer to beginning

                for (int i = 0; i < num_movie; i++)
                {
                    getline(moviefile, line);
                    // find the movie id have stored in the struc in array or not, if yes will not return the value of npos and also found have the
                    //  existence of "." or not, it is necessary no, and then just can combine become the name of a txt file that consists synopsis
                    if (movies[i].movie_ID.find(movie_ID, 0) != string::npos && movie_ID.find('.') == string::npos)
                    {
                        string filename = movie_ID + ".txt";
                        ifstream synopsis_file(filename);

                        while (getline(synopsis_file, synopsis_line))
                            cout << synopsis_line << endl;// read the file contains synopsis

                        found_movie_id = true;  // set variable to true in order to check validation of movie_id
                        break;  // exit the loop after finding the movie ID once since it is for loop
                    }
                }

                if (!found_movie_id)
                    cout << "Invalid movie ID!! Please check the movie ID and key in again. " << endl;

                moviefile.close();

                cout << "\nDo you continue to see another synopsis of the movie? (<Q>uit to exit / Key in any key to continue) : ";
                cin >> continues;
                cout << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (toupper(continues) == 'Q')
                    a = false;
                else
                    a = true;
            }
        }
    }
}

void booking() // booking module
{
    bool a = true, find = false;
    string movie_id, line;
    string seat_code;
    char bookcode[3] = {};

    for (int i = 0; i < num_movie; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                seats[i][j][k] = '#';
            }
        }
    }

    ifstream infile("booking.txt");
    if (infile.is_open())
    {
        while (infile >> seat_code)
        {
            int movieIndex = seat_code[0] - '0';//deduct ASCII value of '0' to take integer , this is the movie type
            char row = seat_code[1];//position of row
            int col = stoi(string(1, seat_code[2])) * 10 + stoi(string(1, seat_code[3])) - 1;//multiple 10 to get tens-digit and plus ones-digit to get the last two digit that is the position of column and then minus 1 to get the position of array
            if (movieIndex >= 0 && movieIndex <= num_movie)
            { // Check if movieIndex is within bounds
                seats[movieIndex - 1][toupper(row) - 'A'][col] = 'X'; // X means seat is taken
            }
        }
        infile.close();
    }

    while (a)
    {
        cout << "Please key in the movie ID that you want to book (<Q>uit to exit this process) : ";
        cin >> movie_id;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(movie_id[0]) == 'Q')
        {
            a = false;
        }
        else if (!isalpha(movie_id[0]) || !isdigit(movie_id[1]) || !isdigit(movie_id[2]))
        {
            cout << "Invalid input for movie ID!!! Please key in again." << endl;
            a = true;
        }
        else
        {

            cout << endl << endl;
            for (int i = 0; i < num_movie; i++)
            {
                if (movies[i].movie_ID.find(movie_id, 0) != string::npos)
                {

                    for (int j = 0; j < 3; j++)
                    {
                        bookcode[j] = movie_id[j];
                    }
                    int number_of_id = stoi(string(1, bookcode[1])) * 10 + stoi(string(1, bookcode[2]));//change the string into integer, to get the last two number of movie id, multiple 10 in order to get tens-digit and then plus one-digit  

                    seat(number_of_id); //call function
                    valid_of_seat(number_of_id, movie_id);// call function

                    find = true;
                    char continues;
                    bool c = true;

                    while (c)
                    {
                        cout << "\nDo you want to book another ticket? <Y>es / <N>o : ";
                        cin >> continues;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl << endl;
                        if (toupper(continues) == 'Y')
                        {
                            c = false;
                            a = true;
                        }
                        else if (toupper(continues) == 'N')
                        {
                            c = false;
                            a = false;
                        }
                        else
                        {
                            cout << "Please key in 'Y' or 'N' to proceed the system.\n" << endl;
                            c = true;
                        }
                    }

                }
            }
            if (!find)
            {
                cout << "Invalid movie ID!!! Please key in again.\n" << endl;
            }
        }
    }
}
void seat(int num_of_id)// display seat
{
    cout << "________\t\t\t\t===================================================================\t\t\t\t________" << endl;
    cout << "| DOOR |\t\t\t\t||                             SCREEN                            ||\t\t\t\t| DOOR |" << endl;
    cout << "|      |\t\t\t\t===================================================================\t\t\t\t|      |" << endl;
    cout << "        \t\t\t\t||                " << movies[num_of_id - 1].movie_name << "       ||\t\t\t\t        " << endl;
    cout << "        \t\t\t\t===================================================================\t\t\t\t        " << endl << endl;
    cout << "        \t\t\t\t\t\t 01 02 03 04 05 06 07 08 09 10" << endl;

    for (int i = 0; i < row; i++)
    {
        cout << "\t\t\t\t\t\t\t" << char('A' + i) << " ";

        for (int j = 0; j < column; j++)
        {
            cout << seats[num_of_id - 1][i][j] << "  ";
        }
        cout << endl;

    }
}

void valid_of_seat(int number_of_id, string movie_id)
{
    string movie_id1 = movie_id;
    char choose_row;
    string choose_column;// type of variable is char because after need to use isdigit()

    cout << "Choose a seat that you prefer." << endl;
    cout << "Choose a row : ";
    cin >> choose_row;
    cout << "Choose the column (Please make sure is two digit): ";
    cin >> choose_column;
    choose_row = toupper(choose_row);

    if (!choose_row)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please key in again." << endl;
    }

    if (isalpha(choose_row) && isdigit(choose_column[0]) && isdigit(choose_column[1]) && choose_column.length() == 2 && choose_row <= 'J' && choose_column[0] <= '1')
    {
        ofstream outfile("booking.txt", ios::app);

        char choose_column_char[2] = {};
        for (int i = 0; i < 2; i++)
        {
            choose_column_char[i] = choose_column[i];
        }
        int choose_column_int = stoi(string(1, choose_column_char[0])) * 10 + stoi(string(1, choose_column_char[1]));// calculate value of column in int type

        if (choose_column_int <= 10)
        {
            if (seats[number_of_id - 1][choose_row - 'A'][choose_column_int - 1] == 'X')
            {
                cout << "\nThat seat is already booked by other people, Please choose a different seat.\n" << endl;
            }
            else if (seats[number_of_id - 1][choose_row - 'A'][choose_column_int - 1] == '#') //book the seat
            {
                seats[number_of_id - 1][choose_row - 'A'][choose_column_int - 1] = 'X';
                cout << "\nThe booking is recorded and you can check it in the cart\n" << endl;

                outfile << number_of_id << choose_row << choose_column << endl;//store seat code into file
                outfile.close();

                string column_row = choose_column.insert(0, 1, choose_row); // get the seat position

                save_into_cart(movie_id1, "cart.txt", column_row); //call function
                seat(number_of_id); //function that use to display the seat 
            }
        }
        else
            cout << "\nPlease key in the number within 01 - 10.\n" << endl;
    }
    else
        cout << "\nPlease check the input. Make sure the row is alphabet within A to J whereas column is digit within 01 to 10.\n" << endl;
}

int array_cart(Cart carts[])
{
    int line_in_cartfile = 0;

    ifstream cartfile("cart.txt");
    if (cartfile.is_open())
    {
        string line;
        while (getline(cartfile, line) && line_in_cartfile < max_line_in_cart)
        {
            Cart cart;
            cart.record_id = line.substr(0, 15);
            cart.record_name = line.substr(15, 56);
            cart.record_seat = line.substr(56, 3);
            cart.record_price = stod(line.substr(64, 5));
            carts[line_in_cartfile] = cart;
            line_in_cartfile++;
        }
    }
    cartfile.close();
    return line_in_cartfile;
}

void save_into_cart(string movie_id1, string filename, string column_row)//save the booking into cart
{
    array_movie(movies, "Movie_information.txt");
    string name;
    double price_movie;
    int line_in_cart = array_cart(carts);

    for (int i = 0; i < num_movie; i++)
    {
        if (movies[i].movie_ID.find(movie_id1) != string::npos)//if the movie id found in the movie information file 
        {
            name = movies[i].movie_name;
            price_movie = movies[i].price;
            for (int j = 0; j <= line_in_cart; j++)
            {
                if (carts[j].record_seat.find(column_row) == string::npos || carts[j].record_id.find(movie_id1) == string::npos) // if the movie id is not found or the position of the seat is not found accordingly in the cart file it will save the booking into the cart.
                {
                    ofstream writefile(filename, ios::app);
                    if (writefile.is_open())
                    {
                        writefile << setprecision(2) << fixed << left
                            << setw(15) << movie_id1 << setw(41) << name << column_row << right << setw(10) << price_movie << endl;
                    }
                    writefile.close();
                    break;
                }
            }
        }
    }
}

void cart(string filename)//review the cart
{
    string line;
    cout << setprecision(2) << fixed << left;
    cout << setw(15) << "Movie ID" << setw(41) << "Movie Name" << setw(8) << "Seat" << setw(9) << "Price(RM)" << "\tQuantity" << endl;
    cout << "===============================================================================================" << endl;

    ifstream printfile(filename);
    if (printfile.is_open())
    {
        // check the stream has reached the end of the file or not if yes printfile.peek() will return EOF means that there are no word exist in the file 
        if (printfile.peek() == EOF)
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||    Not Recorded Found    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            while (getline(printfile, line))
            {
                cout << line << "\t\tx1" << endl;
            }
        }
        printfile.close();
    }
    else
    {
        cout << "File is not found" << endl;
    }
}

bool edit_cart() //delete booking module
{

    cout << endl << endl << endl;
    cout << "========================\t\t========================" << endl;
    cout << "|| 1 || Delete        ||\t\t|| 2 || Exit        ||" << endl;
    cout << "========================\t\t========================" << endl;
    cout << "                       \tOption: ";

    int cart_option;
    bool b;

    cin >> cart_option;
    switch (cart_option)
    {
    case 1:
    {
        string delete_id, delete_seat;
        cout << endl << endl << endl;
        cout << "Please Key in the movie id and accordingly seat that you want to delete. " << endl;
        cout << "Movie ID : ";
        cin >> delete_id;
        cout << "Seat: ";
        cin >> delete_seat;
        cout << endl << endl;

        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        delete_id_seat(delete_id, delete_seat);//call function
        return true;
        break;
    }
    case 2:
    {
        b = exit_page();//call function
        return b;
        break;
    }
    default:
    {
        if (!cart_option)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Input. Please key in again.\n\n" << endl;
        }
        else if (cart_option != 1 && cart_option != 2)
        {
            cout << "\nInvalid Input. Please key in \"1\" / \"2\" to conduct the process.\n\n" << endl;
        }
        return true;
    }
    }
}
void delete_id_seat(string delete_id, string delete_seat)
{
    int num_book_in_cart = array_cart(carts);
    string cart_array[500] = {}, ticket_book[500] = {};//max ticket is 500(5x10x10)
    bool valid_info = false;
    string delete_seat_code;

    ifstream infile("cart.txt");
    for (int i = 0; i < num_book_in_cart; i++) //store the contents of cart file in array
    {
        string line;
        getline(infile, line);
        cart_array[i] = line;
    }

    ifstream infile2("booking.txt"); //in order to store contents of booking file in array

    int count_line = 0;
    string line1;
    while (getline(infile2, line1))
        count_line++;

    infile2.clear(); // reset the file stream to the beginning
    infile2.seekg(0, ios::beg);

    for (int j = 0; j < count_line; j++)
    {
        getline(infile2, ticket_book[j]);
    }

    if (isalpha(delete_id[0]) && isdigit(delete_id[1]) && isdigit(delete_id[2]) && isalpha(delete_seat[0]) && isdigit(delete_seat[1]) && isdigit(delete_id[2]) && delete_id.length() == 3 && delete_seat.length() == 3)
    {
        ofstream outfile("cart.txt");
        ofstream outfile2("booking.txt");

        for (int k = 0; k < num_book_in_cart; k++)
        {
            if (infile.is_open() && carts[k].record_id.find(delete_id, 0) == string::npos || carts[k].record_seat.find(delete_seat, 0) == string::npos)//if delete id or delete seat not found in the cart file
            {
                delete_seat_code = delete_id_seat_code(delete_seat, delete_id);// call the function to get the complete seat code that want to delete
                outfile << cart_array[k] << endl;
            }
        }

        for (int l = 0; l < count_line; l++)
        {
            if (infile2.is_open() && ticket_book[l].find(delete_seat_code, 0) == string::npos)//if the seat code want to delete is not found in bookig file
            {
                outfile2 << ticket_book[l] << endl;
                valid_info = true;
            }
        }

        outfile.close();
        outfile2.close();
    }

    if (!valid_info)
    {
        cout << "\nThe movie id or seat that you want to delete is not found in the cart. Please make sure you have done the booking or not.\n\n" << endl;
    }

    infile.close();
    infile2.close();
}

string delete_id_seat_code(string delete_seat, string delete_id)
{
    char delete_seatcode[3] = {};

    for (int j = 0; j < 3; j++)
    {
        delete_seatcode[j] = delete_id[j];
    }
    int number_of_delete_id = stoi(string(1, delete_seatcode[1])) * 10 + stoi(string(1, delete_seatcode[2]));
    char number = number_of_delete_id + '0';//get the movie type
    string delete_seat_code = delete_seat.insert(0, 1, number);
    return delete_seat_code;
}

void print4()
{
    system("cls");
    cout << "=======================================================================================================================\n";
    cout << "||                                                                                                                   ||\n";
    cout << "||                                                                                                                   ||\n";
    cout << "||                   ______       _     __    __   ___    ___    ______    __      _    _______                      ||\n";
    cout << "||                  |  ___ \\     / \\    \\ \\  / /  |   \\  /   |  |  ____|  |   \\   | |  |__   __|                     ||\n";
    cout << "||                  | |___| |   / _ \\    \\ \\/ /   | |\\ \\/ /| |  | |___    | |\\ \\  | |     | |                        ||\n";
    cout << "||                  |  ____/   / /_\\ \\    |  |    | | \\  / | |  |  ___|   | | \\ \\ | |     | |                        ||\n";
    cout << "||                  | |       / _____ \\   |  |    | |  \\/  | |  | |____   | |  \\ \\| |     | |                        ||\n";
    cout << "||                  |_|      /_/     \\_\\  |__|    |_|      |_|  |______|  |_|   \\___|     |_|                        ||\n";
    cout << "||                                                                                                                   ||\n";
    cout << "||                                                                                                                   ||\n";
    cout << "||                                                                                                                   ||\n";
    cout << "=======================================================================================================================\n";


    cout << "=======================================================================================================================" << endl;
    cout << "||                                                                                                                   ||" << endl;
    cout << "||                                                ~  Discount Menu  ~                                                ||" << endl;
    cout << "||___________________________________________________________________________________________________________________||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||        _________     __     __       |     __       ____         __     __   |    __     _________     __     __  ||" << endl;
    cout << "||       |  _______|   |__|   / /       |    |  |    / ____ \\      |__|   / /   |   |  |   |  _______|   |__|   / /  ||" << endl;
    cout << "||       | |                 / /        |    |  |   / /    \\ \\           / /    |   |  |   | |                 / /   ||" << endl;
    cout << "||       | |_____           / /         |    |  |  | |      | |         / /     |   |  |   | |_____           / /    ||" << endl;
    cout << "||       |______  \\        / /          |    |  |  | |      | |        / /      |   |  |   |______  \\        / /     ||" << endl;
    cout << "||              \\  \\      / /           |    |  |  | |      | |       / /       |   |  |          \\  \\      / /      ||" << endl;
    cout << "||               | |     / /            |    |  |  | |      | |      / /        |   |  |           | |     / /       ||" << endl;
    cout << "||        ______/  /    / /   __        |    |  |   \\ \\____/ /      / /   __    |   |  |    ______/  /    / /   __   ||" << endl;
    cout << "||       |________/    /_/   |__|       |    |__|    \\______/      /_/   |__|   |   |__|   |________/    /_/   |__|  ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||______________________________________|_______________________________________|____________________________________||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "|| ~ For buying the 4 to 6 tickets      |  ~ For buying the 7 tickets or above  |  ~ For Diamond Member Only         ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "|| ~ For Gold Member                    |  ~ For Platinum Member                |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "||                                      |                                       |                                    ||" << endl;
    cout << "=======================================================================================================================" << endl;
    cout << endl << endl << endl;
}

bool payment()//payment module
{
    print4();//call function
    bool a = true;
    int line_in_cartfile = array_cart(carts);
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);
    // display current date and time for decoration 
    cout << left << "Date: " << localTime.tm_mday << "/" << localTime.tm_mon + 1 << "/" << localTime.tm_year + 1900;
    cout << right << setw(96) << "Time: " << setfill('0') << setw(2) << localTime.tm_hour << ":" << setfill('0') << setw(2) << localTime.tm_min << ":" << setfill('0') << setw(2) << localTime.tm_sec << endl;
    cout << setfill(' ');//do not want to apply setwill after display time
    cout << endl << endl;

    ifstream file("cart.txt");
    if (file.is_open())
    {
        if (file.peek() == EOF)
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||    Not Recorded Found    ||" << endl;
            cout << "\t\t==============================" << endl;
            a = false;
        }
        else
            a = true;
    }
    else
    {
        cout << "File is not open." << endl;
        a = false;
    }
    file.close();

    while (a)
    {
        double discount_rate = discount();
        cout << endl << endl;
        double member_discount_rate = member_discount();

        cout << endl << endl;
        cout << "===============================================================================================" << endl;
        cart("cart.txt");
        cout << "===============================================================================================" << endl;

        double subtotal_price = 0;

        for (int i = 0; i < line_in_cartfile; i++)
        {
            subtotal_price += carts[i].record_price;
        }

        double discount_price = subtotal_price * discount_rate;
        double member_discount_price = subtotal_price * member_discount_rate;

        double total_price = subtotal_price - round((discount_price * 100)) / 100 - round((member_discount_price * 100)) / 100;// multiple 100 and divide 100 and then round them to get 2 decimal places
        // rounding adjustment
        int sen = round(fmod(total_price * 100, 10));
        if (sen % 10 >= 5)
            sen += 10;

        sen = sen - (sen % 10);

        double total_price_after_round = total_price - (fmod(total_price * 100, 10) / 100) + (sen / 100.0);

        cout << fixed << showpoint << setprecision(2) << left;
        cout << setw(64) << "Subtotal Price   (RM)" << subtotal_price << endl;
        cout << setw(63) << "Discount         (RM)" << setw(1) << '-' << setw(5) << discount_price << endl;
        cout << setw(63) << "Member Discount  (RM)" << setw(1) << '-' << setw(5) << member_discount_price << endl;
        cout << "===============================================================================================" << endl;
        cout << setw(64) << "Total Price      (RM)" << total_price << endl;
        cout << setw(64) << "Rounding Adjustment  (RM)" << total_price_after_round - total_price << endl;
        cout << "===============================================================================================" << endl;
        cout << setw(64) << "Total Price (after rounding adjustment)  (RM)" << total_price_after_round << endl;
        cout << "===============================================================================================" << endl;

        double find_change = 0;
        find_change = payment_method(total_price_after_round);//call function and return value of change that need to find for customer

        string transaction_id;
        int number_of_file = 0;
        string filename;

        for (int i = 0; i <= 500; i++)//  max number of ticket can book is 500
        {
            if (i >= 0 && i <= 9)
            {
                transaction_id = "000" + to_string(i);
            }
            else if (i >= 10 && i <= 99)
            {
                transaction_id = "00" + to_string(i);
            }
            else if (i >= 100)
            {
                transaction_id = "0" + to_string(i);
            }
            filename = "transacrtion_id_" + transaction_id + ".txt";

            ifstream count_file(filename);

            if (count_file.is_open())
                number_of_file++;
            else if (count_file.fail())//save receipt to the txt file
            {
                ofstream receipt_in_file(filename);
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << "|| Date: " << localTime.tm_mday << "/" << localTime.tm_mon + 1 << "/" << localTime.tm_year + 1900;
                receipt_in_file << setw(65) << "Time: " << setfill('0') << setw(2) << localTime.tm_hour << ":" << setfill('0') << setw(2) << localTime.tm_min << ":" << setfill('0') << setw(2) << localTime.tm_sec << "  ||" << endl;
                receipt_in_file << setfill(' ');
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << "||                              Transaction ID : " << left << setw(44) << transaction_id << "||" << endl;
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << fixed << showpoint << setprecision(2) << left;
                receipt_in_file << "|| " << setw(15) << "Movie ID" << setw(41) << "Movie Name" << setw(8) << "Seat" << setw(9) << "Price(RM)" << "\tQuantity" << "     ||" << endl;
                ifstream cart("cart.txt");
                string line;
                while (getline(cart, line))
                {
                    receipt_in_file << "|| " << line << "\tx1" << "\t     ||" << endl;
                }
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << setw(68) << "Subtotal Price   (RM)" << subtotal_price << endl;
                receipt_in_file << setw(67) << "Discount         (RM)" << setw(1) << '-' << setw(5) << discount_price << endl;
                receipt_in_file << setw(67) << "Member Discount  (RM)" << setw(1) << '-' << setw(5) << member_discount_price << endl;
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << setw(68) << "Total Price      (RM)" << total_price << endl;
                receipt_in_file << setw(68) << "Rounding Adjustment  (RM)" << total_price_after_round - total_price << endl;
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << setw(68) << "Total Price (after rounding adjustment)  (RM)" << total_price_after_round << endl;
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << setw(68) << "Payment method" << method << endl;
                if (method == "E-wallet" || method == "Credit Card")
                    customer_pay = total_price_after_round;
                receipt_in_file << setw(68) << left << "Customer Pay    (RM)" << customer_pay << endl;
                receipt_in_file << setw(68) << left << "Find Change     (RM)" << find_change << endl;
                receipt_in_file << "===============================================================================================" << endl;
                receipt_in_file << "                          ThanK you. Please come again. ^_^\n\n\n                              " << endl;

                cart.close();
                receipt_in_file.close();
                count_file.close();

                ofstream history_file;//store several pieces of information that required to txt file, just give the user can see the brief of record in the transaction record part
                history_file.open("history.txt", ios::app);
                if (history_file.is_open())
                {
                    history_file << fixed << showpoint << setprecision(2) << left;
                    history_file << transaction_id << "\t\t" << customer_pay << "\t\t" << method << endl;
                }
                history_file.close();
                break;
            }
        }

        ofstream delete_content_of_file("cart.txt");//Delete the contents of the cart file because different people have their own cart when booking, so the cart file needs to delete and after the payment, the transaction would be recorded.
        delete_content_of_file.close();

        bool b = true;
        char print_receipt;
        while (b)

        {
            cout << "\n\n\nDo you want to print the receipt? <Y>es / key in any key to Quit : ";
            cin >> print_receipt;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (toupper(print_receipt) == 'Y')
            {
                ifstream print(filename);//print receipt from txt file
                string line;
                while (getline(print, line))
                    cout << line << endl;
                b = true;
                print.close();
            }
            else
            {
                b = false;
                return true;
            }
        }
    }
    char any;
    cout << "\nPlease go to book the ticket(s) first. Thank you ^_^.\n" << endl;
    cout << "Key in any key to Quit : ";
    cin >> any;// in order to quit the page only if no booking in the cart
    return true;

}

double discount()// discount module
{
    int line_in_cartfile = array_cart(carts);
    cout << "Number of ticket(s) booking: " << line_in_cartfile << endl;
    if (line_in_cartfile >= 4 && line_in_cartfile < 7)
    {
        cout << "Discount 5% for total price is applied." << endl;
        return 0.05;
    }
    else if (line_in_cartfile >= 7)
    {
        cout << "Discount 10% for total price is applied." << endl;
        return 0.1;
    }
    else
    {
        cout << "No discount is given. Please note that purchasing four tickets below does not qualify for additional discount. " << endl;
        return 0.0;
    }
}

double member_discount()// member discount
{
    char yes_no;
    string customer_id, password, membership;
    bool a = true, valid_member = true;

    while (a)
    {
        cout << "Is the customer a member?  <Yes> / key in any key for no : ";
        cin >> yes_no;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (toupper(yes_no) == 'Y')
        {
            cout << endl << endl;
            cout << "Customer ID : ";
            cin >> customer_id;
            cout << "Password  : ";
            cin >> password;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ifstream member_file("User_Details.txt");
            string line;
            while (getline(member_file, line))
            {
                User user;
                user.id = line;
                getline(member_file, user.password);
                getline(member_file, user.name);
                getline(member_file, user.nric);
                getline(member_file, user.email);
                getline(member_file, user.phone);
                getline(member_file, user.membership_level);

                if (customer_id == user.id && password == user.password)
                {
                    membership = user.membership_level;
                    if (membership == "gold" || membership == "Gold")
                    {
                        cout << "The customer is " << membership << " member. 5% discount is given." << endl;
                        return 0.05;
                    }
                    else if (membership == "platinum" || membership == "Platinum")
                    {
                        cout << "The customer is " << membership << " member. 10% discount is given." << endl;
                        return 0.1;
                    }
                    else if (membership == "diamond" || membership == "Diamond")
                    {
                        cout << "The customer is " << membership << " member. 15% discount is given." << endl;
                        return 0.15;
                    }
                }
                else
                {
                    valid_member = false;
                }
            }
            member_file.close();
            if (!valid_member)
            {
                cout << "This customer is not a member." << endl;
                a = true;
            }
        }
        else
        {
            cout << "No discount is given." << endl;
            return 0.0;
        }
    }
}

double payment_method(double total_price_after_round)//payment method
{
    bool a = true, b = true;
    double  find_change = 0;
    char reset_payment;

    while (a)
    {
        cout << "What is the payment method of the customer? <E>-wallet / <C>ash / <C>redit <C>ard : ";
        cin >> method;
        // the online payment typically is fit the amount of total price so no need to find the change
        if (method == "E")
        {
            method = "E-wallet";
            find_change = 0;
            b = true;
        }
        else if (method == "C")
        {
            method = "Cash";
            cout << "Amount of the customer payed : ";
            cin >> customer_pay;
            if (!customer_pay)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input. Please pay again." << endl;
                a = true;
                b = false;
            }
            else if (customer_pay)
            {
                find_change = customer_pay - total_price_after_round;
                b = true;
            }
            else
            {
                cout << "Not allowed to key in the negative amount. Please pay again." << endl;
                a = true;
                b = false;
            }
        }
        else if (method == "CC")
        {
            method = "Credit Card";
            find_change = 0;
            b = true;
        }
        else
        {
            cout << "This method is unacceptable and unsupported this system." << endl;
            a = true;
            b = false;
        }

        if (find_change < 0 && method == "Cash")//when the input amount of cash unsufficient
        {
            cout << "The customer is paid by insufficient cash. Please pay again." << endl;
            a = true;
            b = false;
        }

        while (b)
        {
            cout << "Is the payment done? <Y>es / key in any key to reset the payment method : ";
            cin >> reset_payment;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (toupper(reset_payment) == 'Y')
            {
                cout << "===================================" << endl;
                cout << "|| Find change (RM)|| " << right << setw(11) << setprecision(2) << fixed << find_change << "||" << endl;
                cout << "===================================" << endl;
                b = false;
                a = false;
            }
            else
            {
                b = false;
                a = true;
            }
        }

    }
    return find_change;
}

void history_list()
{
    int number = 0;
    cout << "History Record" << endl;
    cout << "===========================================================================" << endl;
    cout << "||  Transaction_id  |  Customer Pay(RM)  |              Method           ||" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    ifstream myfile("history.txt");
    if (myfile.is_open())
    {
        string line, id, price, payment_method;

        while (myfile >> id)
        {
            myfile >> price;
            getline(myfile, payment_method);
            cout << "||       " << left << setw(11) << id << "|     " << setw(15) << price << "| " << setw(14) << payment_method << "     ||" << endl;
        }
        myfile.close();
        cout << "===========================================================================" << endl << endl << endl;
    }
    else {
        cout << "Not recorded found!!\n" << endl;
    }

}


bool history()// search module
{
    bool found = true;
    string filename, transaction_id_search;
    do
    {
        system("cls");
        cout << "\t\t====================================================================================================================\n";
        cout << "\t\t||                                                                                                                ||\n";
        cout << "\t\t||                                                                                                                ||\n";
        cout << "\t\t||                   _     _    _______    ______    _______     ____      ______    __    __                     ||\n";
        cout << "\t\t||                  | |   | |  |__   __|  | _____|  |__   __|  /  __  \\   |  ___ \\   \\ \\  / /                     ||\n";
        cout << "\t\t||                  | |___| |     | |     | |____      | |    |  /  \\  |  | |___| |   \\ \\/ /                      ||\n";
        cout << "\t\t||                  |  ___  |     | |     |_____ |     | |    | |    | |  |  _  _/     |  |                       ||\n";
        cout << "\t\t||                  | |   | |   __| |__    ____| |     | |    |  \\__/  |  | | \\ \\      |  |                       ||\n";
        cout << "\t\t||                  |_|   |_|  |_______|  |______|     |_|     \\ ____ /   |_|  \\_\\     |__|                       ||\n";
        cout << "\t\t||                                                                                                                ||\n";
        cout << "\t\t||                                                                                                                ||\n";
        cout << "\t\t||                                                                                                                ||\n";
        cout << "\t\t====================================================================================================================\n";
        cout << endl << endl;

        history_list();

        cout << "Transaction ID (four digits number): ";
        cin >> transaction_id_search;
        cout << endl;

        if (isdigit(transaction_id_search[0]) && isdigit(transaction_id_search[1]) && isdigit(transaction_id_search[2]) && isdigit(transaction_id_search[2]) && transaction_id_search.length() == 4)
        {
            filename = "transacrtion_id_" + transaction_id_search + ".txt";
            ifstream myfile(filename);
            if (myfile.is_open())
            {
                string line;
                while (getline(myfile, line)) {
                    cout << line << endl;
                    found = true;
                }
                myfile.close();
            }
            else
                cout << "Transaction record not found.\n" << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please only key in four digits number.\n" << endl;
        }

        if (!exit_page())
            transaction_id_search = "Q";

    } while (transaction_id_search != "Q");
    return true;
}

bool option4()
{
    bool continue_program = true;

    while (continue_program)
    {
        membership_interface();
        cout << "\n\t\t\t\t\t\t\t\t Option : "; // prompt user to enter option
        int menu_option;
        cin >> menu_option;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (menu_option == 1)
        {
            acc_registration();
            clear_screen();
        }
        else if (menu_option == 2)
        {
            acc_management();
            clear_screen();
        }
        else if (menu_option == 3)
        {
            continue_program = exit_page();
        }
        else
        {
            cout << "\t\t\tInvalid option! Please enter a number between 1 and 3." << endl;
        }
    }
    return true;
}

bool validate_user_id(string user_id)
{
    if (user_id.length() < 6 || user_id.length() > 12)   // Check if user ID is within 6 to 12 characters
    {
        cout << "\t\tUser ID should be between 6 and 12 characters." << endl;   // Notify the user that the ID should be within the specified range
        return false;
    }
    return true;
}

bool validate_password(string password)
{
    if (password.length() < 8 || password.length() > 20)  // Check if password is within 8 to 20 characters
    {
        cout << "\t\tPassword should be between 8 and 20 characters." << endl;  // Notify the user that the password should be within the specified range
        return false;
    }
    return true;
}

bool validate_confirm_password(string password, string confirm_password)
{
    if (password != confirm_password)     // Check if password same with confirm_password
    {
        cout << "\t\tPassword confirmation does not match password." << endl;   // Notify the user that the password and confirm password should be the same
        return false;
    }
    return true;
}

bool validate_full_name(string full_name)
{
    if (full_name.length() < 2 || full_name.length() > 50)    // Check if the length of name is within 2 to 50 characters
    {
        cout << "\t\tFull name should be between 2 and 50 characters." << endl;    // Notify the user that the length of name is within 2 to 50 characters
        return false;
    }
    return true;
}

bool validate_nric(string nric)
{
    // Check if the length of nric is 12 and all the characters are digits
    if (nric.length() == 12 && isdigit(nric[0]) && isdigit(nric[1]) && isdigit(nric[2]) && isdigit(nric[3]) && isdigit(nric[4]) && isdigit(nric[5]) && isdigit(nric[6]) && isdigit(nric[7]) && isdigit(nric[8]) && isdigit(nric[9]) && isdigit(nric[10]) && isdigit(nric[11]))
    {
        return true;
    }
    else
    {
        cout << "\t\tInvalid Format! Please try again!" << endl;  // Notify the user that the format of nric is wrong
        return false;
    }
}

bool validate_email(string email)
{
    int at_symbol = email.find('@');
    int dot = email.find('.');

    if (at_symbol == string::npos || dot == string::npos || dot < at_symbol || email.find('@', at_symbol + 1) != string::npos || email.find('.', dot + 1) != string::npos)
    {
        cout << "\t\tInvalid email address. Please try again!" << endl;  // Notify the user that the format of email address is wrong
        return false;
    }

    for (int i = 0; i < email.length(); i++)
    {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '-' && email[i] != '_' && email[i] != '@') {
            cout << "\t\tInvalid email address. Please try again!" << endl;
            return false;
        }
    }
}

bool validate_phone_number(string phone_number)
{
    if (phone_number.length() < 9 || phone_number.length() > 11)   // Check if the length of phone number is within 9 to 11 characters
    {
        cout << "\t\tPhone number should be between 9 and 11 digits." << endl;
        return false;
    }
    for (int i = 0; i < phone_number.length(); i++)
    {
        if (!isdigit(phone_number[i]))
        {
            cout << "\t\tPhone number should only contain digits." << endl;   // Notify the user that the format of phone number is wrong
            return false;
        }
    }
    return true;
}

bool validate_membership_level(string membership_level)   // check if membership level is valid
{
    if (membership_level == "Gold" || membership_level == "gold" || membership_level == "Platinum" || membership_level == "platinum" || membership_level == "Diamond" || membership_level == "diamond")
    {
        return true;
    }
    else
    {
        cout << "\t\tInvalid input! Please try again! (Gold/gold/Platinum/platinum/Diamond/diamond)" << endl;
        return false;
    }
}

bool id_used(string user_id)   // Check if the user ID is already used by another user in the User_Details.txt file
{
    ifstream file("User_Details.txt");
    string line;
    while (getline(file, line))
    {
        if (line == user_id)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool nric_used(string user_nric)    // Check if the user nric is already used by another user in the User_Details.txt file
{
    ifstream file("User_Details.txt");
    string line;
    while (getline(file, line))
    {
        if (line == user_nric)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool email_used(string user_email)    // Check if the user email is already used by another user in the User_Details.txt file
{
    ifstream file("User_Details.txt");
    string line;
    while (getline(file, line))
    {
        if (line == user_email)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool phone_used(string user_phone)    // Check if the user phone number is already used by another user in the User_Details.txt file
{
    ifstream file("User_Details.txt");
    string line;
    while (getline(file, line))
    {
        if (line == user_phone)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void membership_interface()
{
    system("cls");
    cout << "\t\t==================================================================================================================================\n";
    cout << "\t\t||                                                                                                                              ||\n";
    cout << "\t\t||                                                                                                                              ||\n";
    cout << "\t\t||         ___    ___    ______    ___    ___    ______     ______    ______     ______    _     _    _______    ______         ||\n";
    cout << "\t\t||        |   \\  /   |  |  ____|  |   \\  /   |  |  ___ \\   |  ____|  |  ___ \\   | _____|  | |   | |  |__   __|  |  ___ \\        ||\n";
    cout << "\t\t||        | |\\ \\/ /| |  | |___    | |\\ \\/ /| |  | |___| |  | |___    | |___| |  | |____   | |___| |     | |     | |___| |       ||\n";
    cout << "\t\t||        | | \\  / | |  |  ___|   | | \\  / | |  |  ___ /   |  ___|   |  _  _/   |_____ |  |  ___  |     | |     |  ____/        ||\n";
    cout << "\t\t||        | |  \\/  | |  | |____   | |  \\/  | |  | |___| \\  | |____   | | \\ \\     ____| |  | |   | |   __| |__   | |             ||\n";
    cout << "\t\t||        |_|      |_|  |______|  |_|      |_|  |_______/  |______|  |_|  \\_\\   |______|  |_|   |_|  |_______|  |_|             ||\n";
    cout << "\t\t||                                                                                                                              ||\n";
    cout << "\t\t||                                                                                                                              ||\n";
    cout << "\t\t||                                                                                                                              ||\n";
    cout << "\t\t==================================================================================================================================\n";
    cout << "\n\n\n";
    cout << "\t\t======================================== \t======================================== \t===================================\n";
    cout << "\t\t|| 1 ||      Account Registration     || \t|| 2 ||      Account Management       || \t|| 3 ||      Exit                ||\n";
    cout << "\t\t======================================== \t======================================== \t===================================\n";
    cout << "\n" << endl;

}

void acc_registration()//registration module
{
    string user_id, password, confirm_password, full_name, nric, email, phone_number, membership_level;
    bool is_valid, valid_level = false;

    clear_screen();
    cout << "\t\t==============================================================================================" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t||                      Welcome to KLN Cinema Membership Registration!                      ||" << endl;
    cout << "\t\t||__________________________________________________________________________________________||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Register to become a member and receive the following benefits:                          ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| - Get the latest movie information by email ~                                            ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| - Enjoy different discount rates for the payment ~                                       ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t==============================================================================================" << endl;
    cout << "\t\t|| ID:                                                                                      ||" << endl;
    cout << "\t\t|| ( Must be within 6-12 characters )                                                       ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Password:                                                                                ||" << endl;
    cout << "\t\t|| ( Must be within 8-20 characters )                                                       ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Confirm Password:                                                                        ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Full Name:                                                                               ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| NRIC:                                                                                    ||" << endl;
    cout << "\t\t|| ( Please use only 12 digit NRIC number )                                                 ||" << endl;
    cout << "\t\t|| ( Example: 97XXXX0X1XXX )                                                                ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Email:                                                                                   ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Phone Number:                                                                            ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Membership Level:                                                                        ||" << endl;
    cout << "\t\t|| 1. Gold     ( 5% discount rate at total payment )                                        ||" << endl;
    cout << "\t\t|| 2. Platinum ( 10% discount rate at total payment )                                       ||" << endl;
    cout << "\t\t|| 3. Diamond  ( 15% discount rate at total payment )                                       ||" << endl;
    cout << "\t\t==============================================================================================" << endl;

    while (true)
    {
        cout << "\t\tDo you want to register for our membership? (Y/N) :";  // Ask the user if they want to register for membership
        string option;
        getline(cin, option);

        if (option == "n" || option == "N")    // If the user enters 'n' or 'N', exit the function
        {
            return;
        }
        else if (option == "y" || option == "Y")  // If the user enters 'y' or 'Y', break out of the loop and continue with registration
        {
            break;
        }
        else   // If the user enters anything else, notify them that their input was invalid and ask again
        {
            cout << "\t\tInvalid input! Please try again." << endl;
        }
    }
    do
    {
        cout << "\t\tID:";
        getline(cin, user_id);
        if (id_used(user_id))
        {
            cout << "\t\tSorry, this ID has been taken by others. Please enter a new one." << endl; // Notify the user about the length requirement for user ID
            is_valid = false;
        }
        else
        {
            is_valid = validate_user_id(user_id);
        }
    } while (!is_valid);

    do
    {
        cout << "\t\tPassword:";
        getline(cin, password);
        is_valid = validate_password(password);   // Validate the password 
    } while (!is_valid);

    do
    {
        cout << "\t\tConfirm Password:";
        getline(cin, confirm_password);
        is_valid = validate_confirm_password(password, confirm_password);   // Validate the confirm password 
    } while (!is_valid);

    do
    {
        cout << "\t\tFull Name:";
        getline(cin, full_name);
        is_valid = validate_full_name(full_name);  // Validate the full name
    } while (!is_valid);

    do
    {
        cout << "\t\tNRIC:";
        getline(cin, nric);
        if (nric_used(nric))
        {
            cout << "\t\tSorry, this NRIC has been taken by others. Please enter a new one." << endl; // Notify the user about the NRIC requirements
            is_valid = false;
        }
        else
        {
            is_valid = validate_nric(nric);   // Validate the nric
        }

    } while (!is_valid);

    do
    {
        cout << "\t\tEmail:";
        getline(cin, email);
        if (email_used(email))
        {
            cout << "\t\tSorry, this email has been taken by others. Please enter a new one." << endl; // Notify the user about the email requirements
            is_valid = false;
        }
        else
        {
            is_valid = validate_email(email);   // Validate the email
        }
    } while (!is_valid);

    do
    {
        cout << "\t\tPhone Number:";
        getline(cin, phone_number);
        if (phone_used(phone_number))
        {
            cout << "\t\tSorry, this phone number has been taken by others. Please enter a new one." << endl;  // Notify the user about the phone number requirements
            is_valid = false;
        }
        else
        {
            is_valid = validate_phone_number(phone_number); // Validate the phone number
        }
    } while (!is_valid);

    do
    {
        cout << "\t\tMembership Level (Gold/Platinum/Diamond):";
        getline(cin, membership_level);
        is_valid = validate_membership_level(membership_level);   // Validate the membership level
    } while (!is_valid);


    ofstream file("User_Details.txt", ios::app);  // Open the file in append mode
    if (file.is_open())
    {
        // Write user details to the file
        file << user_id << endl;
        file << password << endl;
        file << full_name << endl;
        file << nric << endl;
        file << email << endl;
        file << phone_number << endl;
        file << membership_level << endl;
        file.close();
    }
    else
    {
        cout << "\t\tUnable to open file!" << endl;
    }
    // Display a success message and pause the program
    cout << "\t\tThank you for registering our membership! Your user details are recorded." << endl;
    system("Pause");

    return;

}

void acc_management()//update module
{
    clear_screen();
    cout << "\t\t==============================================================================================" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t||                      Welcome to KLN Cinema Membership Management!                        ||" << endl;
    cout << "\t\t||__________________________________________________________________________________________||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| Menu of options:                                                                         ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t|| 1. Update name                                                                           ||" << endl;
    cout << "\t\t|| 2. Update NRIC                                                                           ||" << endl;
    cout << "\t\t|| 3. Update email                                                                          ||" << endl;
    cout << "\t\t|| 4. Update phone number                                                                   ||" << endl;
    cout << "\t\t|| 5. Update membership level                                                               ||" << endl;
    cout << "\t\t|| 6. Save changes and exit                                                                 ||" << endl;
    cout << "\t\t||                                                                                          ||" << endl;
    cout << "\t\t==============================================================================================" << endl;


    while (true)
    {
        cout << "\t\tDo you want to update your membership details? (Y/N) :";  // Ask the user if they want to update their membership details
        string option;
        getline(cin, option);

        if (option == "n" || option == "N")    // If the user enters 'n' or 'N', exit the function
        {
            return;
        }
        else if (option == "y" || option == "Y")  // If the user enters 'y' or 'Y', break out of the loop and continue with registration
        {
            break;
        }
        else   // If the user enters anything else, notify them that their input was invalid and ask again
        {
            cout << "\t\tInvalid input! Please try again." << endl;
        }
    }

    bool loggedIn = false;//log in module

    ifstream file("User_Details.txt");

    if (file.is_open())                      // Check if the file is open
    {
        cout << "\n";
        cout << "\t\tPlease log in to update your details." << endl;
        string id, password;
        cout << "\t\tID:";
        getline(cin, id);
        cout << "\t\tPassword:";
        getline(cin, password);

        string line;
        ofstream temp("temp.txt");       // Create a temporary file to store updated user details

        while (getline(file, line))     // Loop through each line in the file and read the user details
        {
            User user;                   // Create a new User object to hold the details
            user.id = line;
            getline(file, user.password);
            getline(file, user.name);
            getline(file, user.nric);
            getline(file, user.email);
            getline(file, user.phone);
            getline(file, user.membership_level);

            if (id == user.id && password == user.password)     // Check if the entered ID and password match those in the text file
            {
                cout << "\n";
                cout << "\t\tWelcome," << user.name << "!" << endl;
                cout << "\t\tThis is your membership details:" << endl;
                cout << "\t\tNRIC:" << user.nric << endl;
                cout << "\t\tEmail:" << user.email << endl;
                cout << "\t\tPhone number:" << user.phone << endl;
                cout << "\t\tMembership Level:" << user.membership_level << endl;

                loggedIn = true;

                string new_value;
                cout << "\n";
                cout << "\t\tEnter new value for each field (or press Enter to keep current value):" << endl;

                // Prompt user for new values for each field and update user object accordingly
                cout << "\t\tFull Name: ";
                getline(cin, new_value);
                if (!new_value.empty())
                {
                    if (validate_full_name(new_value))
                    {
                        user.name = new_value;
                    }
                }

                cout << "\t\tNRIC: ";
                getline(cin, new_value);
                if (!new_value.empty())
                {
                    if (validate_nric(new_value))
                    {
                        user.nric = new_value;
                    }

                }

                cout << "\t\tEmail: ";
                getline(cin, new_value);
                if (!new_value.empty())
                {
                    if (validate_email(new_value))
                    {
                        user.email = new_value;
                    }
                }

                cout << "\t\tPhone Number: ";
                getline(cin, new_value);
                if (!new_value.empty())
                {
                    if (validate_phone_number(new_value))
                    {
                        user.phone = new_value;
                    }
                }

                cout << "\t\tMembership Level: ";
                getline(cin, new_value);
                if (!new_value.empty())
                {
                    if (validate_membership_level(new_value))
                    {
                        user.membership_level = new_value;
                    }
                }

                cout << "\t\tYour details have been updated." << endl;
                system("Pause");

                temp << user.id << endl; // Write the updated user details to the temporary file
                temp << user.password << endl;
                temp << user.name << endl;
                temp << user.nric << endl;
                temp << user.email << endl;
                temp << user.phone << endl;
                temp << user.membership_level << endl;

            }
            else
            {
                temp << line << endl; // Write the details of other users to the temporary file
                temp << user.password << endl;
                temp << user.name << endl;
                temp << user.nric << endl;
                temp << user.email << endl;
                temp << user.phone << endl;
                temp << user.membership_level << endl;
            }
        }

        file.close();
        temp.close();

        remove("User_Details.txt");               // Delete the old file
        rename("temp.txt", "User_Details.txt");   // Rename the temporary file to the original file name

    }

    if (!loggedIn)  // If the ID and password do not match, deny access
    {
        cout << "\t\tAccess denied." << endl;
        system("Pause");
        return;
    }
}

void clear_screen()
{
    system("cls");
}
