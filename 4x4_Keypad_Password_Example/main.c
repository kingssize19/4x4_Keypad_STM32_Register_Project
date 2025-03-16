#include "gpio.h"
#include "uart.h"

#define PASSWORD_LENGTH 4
char password[PASSWORD_LENGTH + 1];  // Null terminator için 1 ekstra alan

int main(void)
{
    gpio_init();
    uart_init();

    int index = -1;

    while (1) {
        char key = keypad_read();

        // Şifreyi istemek için "*" tuşuna basılınca mesaj göster
        if (key == 'A') {
            send_string("Sifre girin : ");
            index = 0;
            continue;
        }

        if (index == -1){
        	continue;
        }

        // Geçerli bir tuş okunduysa
        if (key != 0) {
            // Şifreyi tamamlamak için "#" tuşuna basıldığında
            if (key == '#' && index == PASSWORD_LENGTH) {
                password[index] = '\0';  // Şifreyi sonlandır
                send_char('\n');
                send_string("Girilen sifre: ");
                send_string(password);  // Şifreyi terminale gönder
                send_char('\n');
                index = -1;  // Şifre girişini sıfırla
            }
            // Şifreyi girmeye devam et
            else if (index != -1 && index < PASSWORD_LENGTH) {
                password[index] = key;  // Girilen karakteri şifre dizisine kaydet
                send_char('*');  // Her karakter için '*' göster
                index++;
            }
        }
    }
}
