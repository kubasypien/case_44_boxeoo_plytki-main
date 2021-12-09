#ifndef active_leds_hpp
#define active_leds_hpp

#include <cstdio>

class active_leds{
private:
    uint8_t* led_indexes;
    uint8_t size;

public:
    active_leds(uint8_t _size): size{ _size }, led_indexes{ (uint8_t*)malloc(_size * sizeof(uint8_t)) } {
        for(uint8_t i = 0; i < size; ++i){
          led_indexes[i] = i;
        }
    }
    active_leds(const active_leds& al): size{ al.size }, led_indexes{ (uint8_t*)malloc( al.size * sizeof(uint8_t)) } { 
        for(uint8_t i = 0; i < size; ++i){
          led_indexes[i] = al.led_indexes[i];
        }
    }

    uint8_t len() const{
        return size;
    }

    active_leds(const active_leds&& al): size{ al.size }, led_indexes{ al.led_indexes } { }
    ~active_leds(){
        free(led_indexes);
    }
    void shift_index(int max){
        for(int i = 0; i < size; ++i){
            if(led_indexes[i] == max){
                led_indexes[i] = 0;
            }
        }
    }
    active_leds operator++(int){
        auto tmp = *this;
        for(uint8_t i = 0; i < size; ++i){
          ++led_indexes[i];
        }
        return tmp;
    }
    active_leds operator--(int){
        auto tmp = *this;
        for(uint8_t i = 0; i < size; ++i){
          --led_indexes[i];
        }
        return tmp;
    }
    bool operator==(int x) const{
        for(uint8_t i = 0; i < size; ++i){
            if(led_indexes[i] == x){
                return true;
            }
        }
        return false;
    }
    active_leds& operator=(const active_leds& a) = delete;
    active_leds& operator=(const active_leds&& a){
        free(led_indexes);
        size = a.size;
        led_indexes = a.led_indexes;

        return *this;
    }
};

#endif