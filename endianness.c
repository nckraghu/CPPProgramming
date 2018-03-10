int main(){
 
    int test_int = 1;

    printf("%d\n", *(char*)&test_int);
    printf("%d\n", *((char*)&test_int + 1));
    printf("%d\n", *((char*)&test_int + 2));

    return 0;
}