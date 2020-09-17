#include <iostream>
namespace {
    void sort(int *array, int len, int MAX_VAULE, int *sa) {
        int *cnt = new int[MAX_VAULE];
        for(int i=0;i<len;i++){
            cnt[array[i]]++;
        }
        for(int i=1;i<MAX_VAULE;i++){
            cnt[i]+=cnt[i-1];
        }
        for(int i=0;i<len;i++){
            sa[cnt[array[i]]--]=i;
        }
        delete []cnt;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
