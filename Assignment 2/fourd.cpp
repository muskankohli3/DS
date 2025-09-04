#include <iostream>

int main() {
    int n;
    std::cin >> n;
    char strings[100][101];
    for(int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int k = 0;
            bool swap_needed = false;
            while(strings[i][k] != '\0' && strings[j][k] != '\0') {
                if(strings[j][k] < strings[i][k]) {
                    swap_needed = true;
                    break;
                } else if(strings[j][k] > strings[i][k]) {
                    break;
                }
                k++;
            }
            if(!swap_needed && strings[i][k] != '\0' && strings[j][k] == '\0') {
                swap_needed = true;
            }
            if(swap_needed) {
                char temp[101];
                int l = 0;
                while(strings[i][l] != '\0') {
                    temp[l] = strings[i][l];
                    l++;
                }
                temp[l] = '\0';
                l = 0;
                while(strings[j][l] != '\0') {
                    strings[i][l] = strings[j][l];
                    l++;
                }
                strings[i][l] = '\0';
                l = 0;
                while(temp[l] != '\0') {
                    strings[j][l] = temp[l];
                    l++;
                }
                strings[j][l] = '\0';
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        std::cout << strings[i] << std::endl;
    }
    return 0;
}
