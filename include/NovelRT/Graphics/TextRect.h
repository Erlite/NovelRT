// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_GRAPHICS_TEXTRECT_H
#define NOVELRT_GRAPHICS_TEXTRECT_H

#ifndef NOVELRT_H
#error Please do not include this directly. Use the centralised header (NovelRT.h) instead!
#endif

namespace NovelRT::Graphics {
  class TextRect : public RenderObject {

  private:
    void reloadText();

    std::string _fontFileDir;
    std::string _previousFontFileDir;
    std::string _text;
    std::vector<std::unique_ptr<ImageRect>> _letterRects;
    std::map<GLchar, GraphicsCharacterRenderData> _fontCharacters;
    LoggingService _logger;
    RGBAConfig _colourConfig;
    float _fontSize;

  protected:
    void configureObjectBuffers() final;

  public:
    TextRect(const Transform& transform,
      int layer,
      ShaderProgram programId,
      Camera* camera,
      float fontSize,
      const std::string& fontFileDir,
      const RGBAConfig& colourConfig);

    void drawObject() final;

    inline const RGBAConfig& getColourConfig() const {
      return _colourConfig;
    }

    inline RGBAConfig& getColourConfig() {
      return _colourConfig;
    }

    void setColourConfig(const RGBAConfig& value);

    std::string getText() const;
    void setText(const std::string& value);

    void setActive(bool value) override;

  };
}

#endif //NOVELRT_GRAPHICS_TEXTRECT_H
