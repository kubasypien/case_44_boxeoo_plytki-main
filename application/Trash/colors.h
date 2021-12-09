#ifndef colors_h
#define colors_h

class rgbw_colors{
public:
  enum class rgbw_color{
      RED, WHITE, GREEN, BLUE, ORANGE, YELLOW,
      CYAN, MAGENTA, NONE, MAX
  };

  static uint32_t Color(rgbw_color color) {
      switch(color){
          case rgbw_color::RED: return Adafruit_NeoPixel::Color(255, 0, 0); break;
          case rgbw_color::WHITE: return Adafruit_NeoPixel::Color(0, 0, 0, 255); break;
          case rgbw_color::GREEN: return Adafruit_NeoPixel::Color(0, 255, 0); break;
          case rgbw_color::BLUE: return Adafruit_NeoPixel::Color(0, 0, 255); break;
          case rgbw_color::ORANGE: return Adafruit_NeoPixel::Color(255, 165, 0); break;
          case rgbw_color::YELLOW: return Adafruit_NeoPixel::Color(255, 255, 0); break;
          case rgbw_color::CYAN: return Adafruit_NeoPixel::Color(0, 255, 255); break;
          case rgbw_color::MAGENTA: return Adafruit_NeoPixel::Color(255, 0, 255); break;
          case rgbw_color::NONE: return Adafruit_NeoPixel::Color(0, 0, 0); break;
          case rgbw_color::MAX: return Adafruit_NeoPixel::Color(255, 255, 255, 255); break;
          default: return 0;
      }
  }
};

rgbw_colors::rgbw_color& operator++(rgbw_colors::rgbw_color& c){
    using rgbw = rgbw_colors::rgbw_color;

    switch(c){
          case rgbw::RED: c = rgbw::WHITE; break;
          case rgbw::WHITE:c = rgbw::GREEN; break;
          case rgbw::GREEN: c = rgbw::BLUE; break;
          case rgbw::BLUE: c = rgbw::ORANGE; break;
          case rgbw::ORANGE: c = rgbw::YELLOW; break;
          case rgbw::YELLOW: c = rgbw::CYAN; break;
          case rgbw::CYAN: c = rgbw::MAGENTA; break;
          case rgbw::MAGENTA: c = rgbw::RED; break;
          case rgbw::NONE: c = rgbw::NONE; break;
          case rgbw::MAX: c = rgbw::MAX; break;
      }
      return c;
}

#endif