#ifndef LIB_H_
#define LIB_H_
void hello(void);

#ifdef LIB_IMPL
void hello(void){
    printf("hello\n");
}
#endif // LIB_IMPL
#endif // LIB_H_
