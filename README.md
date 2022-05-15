# RussianRomanizer
Arduino, M5Stackでロシア語をラテン文字表記化するプログラム。  
[変換法は2010年以降のロシアのパスポートに準拠](https://ja.wikipedia.org/wiki/ロシア語のラテン文字表記法#新表記法_(2010-))。  

## 関数説明
### rtor()
#### 説明:
キリル文字で書かれたロシア語の文章をラテン文字表記に変換する。  
ロシア語のキリル文字以外はそのまま。  
[変換法は2010年以降のロシアのパスポートに準拠](https://ja.wikipedia.org/wiki/ロシア語のラテン文字表記法#新表記法_(2010-))。 

#### 構文:
`String rtor(const String russianText)`  

#### 返り値
ラテン文字表記化されたロシア語文章(`String`型)  
