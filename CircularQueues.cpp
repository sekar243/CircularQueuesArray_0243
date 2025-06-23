/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays,
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for insert elements from queues
 * - show data / display
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * - Nama   : Sekar Kinasih
 * - Nim    : 20240140243
 * - Kelas  : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues 
 * 
 */
class Queues 
{
private:
    static const int max = 5;
    int FRONT; /// private variable front to indicate first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for  maximum capasity of element
    int queue_array[5]; /// private variable queue_array to store elements

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data ke dalam Queues
     *  
     * 
     */
    void insert() {
        int num; /// variable untuk menyimpan nilai bilangan bulat
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // cek apakah antrian masih kosong
        if (FRONT == -1) {
            FRONT =0;
            REAR =0;
        }
        else {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else    
                REAR = REAR +1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk memastikan queues tidak kosong sebelum menghapusnya
     * 
     */
    void remove() {
        //cek apakah antrian kosong
        if (FRONT == -1) { 
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) { 
            FRONT = -1;
            REAR = -11;
        }
        else {
            // jika elemen yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max -1) 
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief method untuk menampilkan seluruh element yang ada pada queues
     * 
     */
    void display() {
        int FRONT_position = FRONT; /// variable FRONT_position untuk menyimpan nilai pada variable FRONT digunakan dalam antrian tanpa mengubah nilai awal
        int REAR_position = REAR; /// variable REAR_position untuk menyimpan nilai pada variable REAR digunakan dalam antrian tanpa mengubah nilai awal

        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout <<"\nElements in the queue are...\n";

        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] <<"  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_parsition > REAR_parsition, insert dari FRONT hingga akhir array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] <<"  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            //iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] <<"  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief  method untuk memanggil fungsi insert, remove, display pada fungsi utama
 * 
 * @return int 
 */
int main()
{
    Queues q; /// mendeklarasikan objek q dari queues 
    char ch; /// mendeklarasikan objek ch dari char

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "5. Exit your choice (1-4:) ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {

                q.insert();
                break;
            }
            case '2':
            {

                q.remove();
                break;
            }
            case '3':
            {

                q.display();
                break;
            }   
            case '4':
            {

                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }      
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
