    #include <cstdio>
    #include <cstdlib>
    #include <ctime>
    int main(){
        int* k = new int;
        if((int)k%5) printf("Yonsei");
        else printf("Korea");
        delete k;
    }
