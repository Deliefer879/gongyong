# DX

* ## DX API 접두사
  |   |   |
  |---|---|
  |IA|Input-Assembler Stage|
  |VS|Vertex_Shader Stage|
  |HS|Hull Shader Stage|
  |DS|Domain ShaderStage|
  |TS|Tessellation Stage|
  |GS|Geometry-Shader Stage|
  |SO|Stream-Output Stage|
  |RS|Resterizer Stage|
  |PS|Pixel-Shader Stage|
  |OM|Output-Merger Stage|
  |CS|Compute Stage|

* ## WDDM
  * 윈도우 비스타 이후 등장한 드라이버 모델로 이전 윈도우에서는 렌더링에  
    GDI와 DX를 사용했지만 WDDM에서는 GDI를 사용하지 않고 DX만 사용한다.
</br></br>

* ## COM( Component Object Model )
  * 소프트웨어 컴포넌트를 개발하기 위한 MS Window의 주요 소프트웨어 개발 플랫폼.
  * COM의 가장 큰 특징은 한번 설계가 완료되면 변하지 않는다는 점으로  
    이는 COM을 사용하는 프로그램이나 COM을 제공하는 프로그램이 서로 다른 버전을  
    사용하더라도 문제없이 동작할 수 있도록 한다.
  * COM은 GUID를 이용하여 객체를 식별하기 때문에 같은 이름의 클래스를 사용가능하다.
</br></br>

* ## DoubleBuffering
  * 스크린 화면에 해당하는 전면 버퍼에 직접 랜더링시 랜터링 과정이 보여 화면이 깜빡이는 현상이 발생한다.  
  그래서 전면 버퍼에 랜더링을 하지 않고 랜더링 결과를 백그라운드 버퍼에 저장한 후  
  버퍼를 복사(bliting)하거나 버퍼 포인터를 교체(page flipping)하는 방식을 사용한다.
  </br></br>

* ## COM_Ptr
  * window runtime lib의 C++의 shader pointer와 비슷한 ptr  
  * GetAddressOf()를 이용해 실제 주소를 얻고  
    Get()을 통해 객체에 접근한다.