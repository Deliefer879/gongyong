# DX_3D

## 목차
 1. [3D 기초](#3D-기초)


* ## 3D 기초
  * 3차원 그래픽스의 처리과정은 기하학적인 형상을 제작하는 모델링 단계와  
  모델링 된 객체를 2차원 평면에 투영하는 투영 단계  
  그리고 투영된 객체에 색상과 명암등을 부여하는 랜더링 단계로 크게 나뉜다.
    * **모델링 단계 -> 투영 단계 -> 랜더링 단계**
  * 3D 데이터의 표현 방식으로는 와이어 프레임, 폴리곤, 솔리드 3가지가 있다.
  * ### 모델링 단계
    * 다수의 페이스 및 폴리곤이 연결되어 어떤 형태로 만들어 질 때 이를 보통 모델 객체(Object)라고 표현한다.

    * 객체 생성 방법
      1) Polygon Mesh
      2) Parametric Surface Modeling
      3) Sweeping
      4) Solid Modeling
      5) Fractal Geometry
      6) Particle System

    * #### Solid Modeling
      * 솔리드 모델링 방법은 CSG(Constructive Solid Geometry)와 같은 방법으로  
      기본 객체들에 집합 연산을 수행하여 새로운 객체를 만드는 방법이다.
    
    * ### 투영 단계
      * 모델링 한 객체들을 모니터와 같은 2차원 평면에 투영하는 과정이며  
      기하 변환, 좌표계 변환, 투영 변환이 해당되면 이 모든 처리 변환 단계를 뷰잉 변환(그래픽 랜터링 파이프라인)이라고 한다.
  </br></br>

  * ## View port
    * 뷰 포트란 장면 연출 영역 중에서 일정한 범위 및 전체 영역을 출력 장치에 표현하는 것
  </br></br>

  * ## Shader
    * 쉐이더 파일의 확장자는 상관없으나 일반적으로  
    정점 쉐이더 : .vsh, 픽셀 쉐이더 : .psh,      기하 쉐이더 : .gsh, 이펙트 파일 : .fx로 사용한다.  

    또한 한개에 파일에 몰아놔도 사용은 가능하다.
    * 쉐이더 연산은 각 픽셀마다 수행되는 연산으로 GPU에 의해 수행된다.
    * 쉐이더 코드는 별도의 파일(확장자 상관 X)을 만들어 파일에 저장하고  
    이를 컴파일하여 쉐이더 객체를 생성한다.
    * 쉐이더 함수에 전달되는 파라미터는 SemanticName을 이용해 구분한다.
    * 쉐이더 연산시 행렬 곱은 행 * 열이 아닌 행 * 행으로 계산된다.  
    그래서 행렬 계산시 곱할 행렬을 전치해서 사용해야 한다.
    * DX9까지는 사용가능한 레지스터가 약 255개로 제한되어 있었지만  
    DX10부터는 레지스터의 개수가 255*255개로 늘어나서 레지스터의 개수를 신경쓰지 않아도 된다.
    * 쉐이더에 상수 버퍼를 만들 시 레지스터 단위(float4)로 저장되어야 하며  
    만들어진 상수 버퍼의 값들은 전역 변수처럼 사용가능하다.

  * ## Alpha Blending
    * 알파 블렌딩은 투명도를 표현하기 위한 기법으로  
    픽셀의 색상값에 알파값을 곱한 후 이를 렌더링 대상 픽셀의 색상값에 더하는 방식이다.
    * 알파 블랜딩 공식
    ```
    DstColor = SrcColor * SrcAlpha + DstColor * (1 - SrcAlpha)
    
    ex) 
    (0.4f,0.6f,0)  = (1,0,0)  *   0.4f   +  (0,1,0) * (1 - 0.4f) 
    ```

  * ## Map
    * 맵의 기본 정보 : 한 방향으로 셀(2개의 Face로 구성하는 사각 평면)을 8개 구성하려면 정점은 9개 필요하다.  
    일반적으로 작업의 편의성을 위해 정점을 2^n + 1개로 생성한다.
    (ex) 가로 및 세로로 8개씩 셀을 생성 -> 9x9개의 정점)

    * 정점 레이아웃의 데이터는 기본적으로 PNCT를 포함하도록 한다.  
      P : POSITION : 정점의 위치  
      N : NORMAL   : 정점의 노말 벡터
      C : COLOR    : 색
      T : TEXCOORD : texture

    * 

  * ## 뷰 및 투영 변환
    * 뷰 변환 : 월드 공간에 배치된 정점을 카메라 공간으로 변환 하는 처리  
    뷰 행렬 = 카메라 이동 행렬 * 카메라 회전 행렬  
            = 월드 이동 행렬^-1 * 월드 회전 행렬^-1  
            (카메라가 월드에서 이동, 회전 한다는 것은 월드 정점이 반대로 이동, 회전되는 것이므로)

    * 뷰 행렬 생성(외적)
      1) 카메라 위치(pos), 바라보는 타겟(target), up 벡터(upVec) <- UP 벡터는 일반적으로 {0,1,0}을 전달한다.)
      2) nomal(target - pos) : zAxis
      3) nomal(cross(up, zAxis)) : xAxis
      4) nomal(cross(zAxis, xAxis))
      5)    |   |   |   |   |
            |---|---|---|---|
            |xAxis.x|yAxis.x|zAxis.x|0|
            |xAxis.y|yAxis.y|zAxis.y|0|
            |xAxis.z|yAxis.z|zAxis.z|0|
            |-dot(xAxis, pos)|-dot(yAxis, pos)|-dot(zAxis, pos)|1|
    * 뷰 행렬 생성(내적)-> 그람 슈미트
      1) 카메라 위치(pos), 바라보는 타겟(target), up 벡터(upVec) <- UP 벡터는 일반적으로 {0,1,0}을 전달한다.)
      2) 임시 up벡터를 시선 벡터(target - pos)와 직교가 되도록 만든다.
      3) 수정한 up벡터를 시선 벡터와 외적해 right vec을 구한다.

    * 오브젝트 회전 행렬
      * 뷰 행렬의 구현과 거의 동일 하지만 각 축의 벡터를 전치 하지 않고 그대로 사용하는 것이 다르다.

    * 평행(직교) 투영
      * 보통 화면 비율이 다르기 때문에 종횡비를 고려해야 한다.  
      * DX는 x, y : -1 ~ 1, z : 0 ~ 1
      * 근단면은 투영되는 최소 거리, 원단면은 투영되는 최대 거리
      * OffCenter : 원하는 영역만 직교 투영
  </br></br>

  * ## Height Map
    * SRV는 GPU가 랜더링 중 텍스처에 접근하여 읽는 방법을 나타내는 객체로 응용 프로그램(cpu)에서 접근하기 위해서는 텍스터를 생성 시 D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE 플래그를 사용하면 된다.
    * 일반적으로 리스스에 대한 엑세스는 다음 API에 의해 실행된다.
      * CPU : ID3D11DeviceContext::Map
      * GPU
        1) ID3D11DeviceContext::CopySubresourceRegion
        2) ID3D11DeviceContext::CopyResource
        3) ID3D11DeviceContext::UpdateSubResource

        | 리소르를 사용하는 방법 | Default | Dynamic | Immutable | Staging |
        |---|---|---|---|---|
        | GPU에 의한 읽기 | 가능 | 허용 | 가능 | 허용 1,2 |
        | GPU에 의한 쓰기 | 허용1 | | | 허용 1,2 |
        | CPU에 의한 읽기 | | | | 허용 1,2 |
        | CPU에 의한 쓰기 | | 가능 | | 허용 1,2 |

    * 텍스처의 크기는 실제 크기와 다를 수 있다.  
      (DX에서 2^n이 되도록 padding값을 넣음)
  </br></br>
      
  * ## 정점 노말 계산
    * 각 Vertex의 NomalVector는 Vertex가 포함된 Face의 NomalVector의 합이다.
    * 단 Face의 NomalVector의 합으로 계산 시 각 Face의 크기가 다르다면  
    NomalVector로 저장하는 것이 아니라 그대로 저장 후 계산해야 Face의 영향력이 적용된다.
  </br></br>

  * ## 정점 컬러 계산
    * 램버트 조명 공식 : fDot = (LightVector * -1) | VertexNormal  
      LightVector * -1 : 정점에서 빛의 방향으로 향하는 벡터로 만들어 내적 결과가 양수가 되도록 한다.
  </br></br> 

  * ## 노말 변환 
    * 노말 벡터는 정점의 위치와 같이 변환되어야 한다. 그러나 변환에 Scale이 포함되어 있는 경우  
    노말 벡터의 방향이 틀어지는 문제가 있다. 이를 해결하기 위해서는 변환에 사용하는 World 행렬의 역 행렬의 전치 행렬을 사용해야 하며  
    이를 보통 노말 변환이라 한다.
    * Correct Normal = Normal * (World 행렬^-1)^T  
      V = Edge Vector, N = Normal Vector  
      N | V = Cross(V, N^T) = 0  <== **내적을 행렬로 표현**  
      V M M^-1 N^T = 0  
      V' = V M, N' = M^-1 N^T  
      N' = (M^-1 N^T)^T  
      N' = N (M^-1)^T  
  </br></br>

  * ## 지형 높이갚 얻기
    1) 위치의 World 좌표를 지형의 로컬 좌표로 변환한다.  
        * 맵의 중앙을 원점으로 사용 시 가로 및 세로의 셀의 인덱스를  
        2로 나누어 절반으로 지정 후 위치 posX, posY를 더해주면 해당하는 셀을 얻을 수 있다.  
        단 이때 셀의 크기는 1이며 아닐 경우 위치를 셀의 크기로 나누어야 한다.
    2) 셀의 인덱스를 이용해 해당하는 셀의 높이값을 얻는다.
        * 셀을 구성하는 4개의 정점을 구한다.
        * 이후 TL 또는 BL 정점을 기준으로 X, Z축 변위를 계산한다.
        * 변위 값을 이용하여 위치가 셀의 어느 Face에 있는지 계산한다.  
          fDeltaX + fDeltaZ < 1 : TL Face   
          fDeltaX + fDeltaZ > 1 : BR Face
        * Face에 따라 위치를 보간하여 높이 값을 찾는다.  
          TL Face인 경우 : 높이값 = A정점 높이 + 가로 정점 차이 + 세로 정점 차이  
          BR Face인 경우 보간에 사용되는 delta값을 1-delta로 바꿔준다.
  </br></br>

  * ## Depth buffering
    * Depth buffering : 한 물체의 픽셀들이 다른 물체보다 앞에 있는지 판정하기 위해 사용하는 기법.
    * Z-buffer : 3차원 메모리를 렌더링 할 때 보이는 점에서 다각형과 같은 물체까지의 거리(Z값)을 보관해두는 기억 장치
    * Z-buffer를 생성 시 backbuffer의 크기와 같은 크기를 생성해야 하는데 이때 backbuffer가 아닌 swapchain의 데이터를 이용해 생성해도 된다.
    * Z-buffer를 생성한 뒤 ID3d11DepthStaencilState를 이용하여 Z-buffer를 사용할 수 있다.  
    DepthSteancilState는 여러개를 생성할 수 있으며 이를 이용해 각 객체에 Depth buffering을 적용할 수도 적용하지 않을수도 있다.


  * ## FBX
    * fbx 파일은 FBXSDK Lib를 이용해 읽을 수 있다.
      1) fbx sdk download
      2) FBX SDK 폴더 생성 후 inc, lib 복사
      3) TFbxImport 클래스 생성 및 환경 설정
         * fbx dll이 시스템에 있다면 dll을 실행 파일과 같은 폴더에 없어도 된다.
      4) Fbx는 manager를 통해 메모리를 할당하고 이를 통해 scene을 생성한다.  
      그래서 smart pointer를 사용할 필요가 없다.
    * PreProcess : 일반적으로 3D 파일은 트리구조(scene graph)로 구성되어 있으며  
    이 트리를 순회하면 fbx파일에 포함된 모든 정보를 얻을 수 있다.
    * 파일의 노드는 각각 다른 정보를 지니고 있으며 필요한 정보에 따라 노드에서 정보를 얻은 뒤 사용하면 된다.
    * fbx는 기존에 사용하던 dx math가 fbx math를 사용한다.
    * polygon은 face가 2개인 경우와 face가 1개인 경우가 있다.
      그래서 polygon이 몇개의 face로 구성되어 있는지 알아야 한다.
    * fbx는 max 좌표계를 사용하기 때문에 z,y가 바뀌어 있으며 texture정보도 바뀌어 있다.
    그래서 값을 dx에서 사용가능 하도록 바꿔주어야 한다.
        
    1권 p.774 ~ end 