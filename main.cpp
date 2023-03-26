#include <iostream>
using namespace  std;

string decrypt(string key, string message_open, int length){

    string message_closed = "";

    for(int i = 0; i < message_open.length(); i++){

        int key_letter = key[i%length];
        int letter = message_open[i];
        int letter_code = (letter + key_letter)%128;

        message_closed += letter_code;
    }

    return  message_closed;
}

string encrypt(string key, string message_closed){

    string message_open = "";

    int length = key.length();

    for(int i = 0; i < message_closed.length(); i++) {

        int key_letter = key[i % length];
        int letter = message_closed[i];
        int letter_code = (letter - key_letter + 128) % 128;
        message_open += letter_code;
    }

    return message_open;
}

string generate_key(int length){

    string key = "";

    srand(time(NULL));

    char ascii[128];
    for(int i = 0; i < 128; i++) {

        ascii[i] = i;
    }

    random_shuffle(&ascii[0], &ascii[128]);

    for (int n = 0; n < length; n++){

        key += ascii[rand()%128];
    }

    return key;

}

int main() {

    int input_1 = 1;
    int input_2 = 1;
    string key = "";
    string message_open = "";
    string message_closed = "";
    int length;

    while (input_1 != 3){

        cout << endl << "1: Decrypt" << endl << "2: Encrypt" << endl << "3: Terminate" << endl << endl;

        cin >> input_1;

        if (input_1 == 1){

            cout << endl << "1: Own Key" << endl << "2: Generate Key" << endl << endl;

            cin >> input_2;

            if (input_2 == 1 ){

                cout << endl << "Please enter the key:" << endl << endl;
                cin >> key;
                cout << endl << "Please enter the length of the key:" << endl << endl;
                cin >> length;
                cout << endl << "Please enter the message:" << endl << endl;
                cin >> message_open;

                message_closed = decrypt(key, message_open, length);
                cout << endl << "The message is: " << message_closed << endl << endl;

            } else if (input_2 == 2){

                cout << endl << "Please enter the length of the key:" << endl << endl;
                cin >> length;

                key  = generate_key(length);
                cout << endl << "The key is: " << key << endl << endl;

                cout << endl << "Please enter the message:" << endl << endl;
                cin >> message_open;

                message_closed = decrypt(key, message_open, length);
                cout << endl << "The message is: " << message_closed << endl << endl;

            }
        }

        if (input_1 == 2){

            cout << endl << "Please enter the key:" << endl << endl;
            cin >> key;
            cout << endl << "Please enter the message:" << endl << endl;
            cin >> message_closed;

            message_open = encrypt(key, message_closed);
            cout << endl << "The message is: " << message_open << endl << endl;
        }

        }
    return 0;
}