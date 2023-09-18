# DX

* ## DX API ���λ�
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
  * ������ ��Ÿ ���� ������ ����̹� �𵨷� ���� �����쿡���� ��������  
    GDI�� DX�� ��������� WDDM������ GDI�� ������� �ʰ� DX�� ����Ѵ�.
</br></br>

* ## COM( Component Object Model )
  * ����Ʈ���� ������Ʈ�� �����ϱ� ���� MS Window�� �ֿ� ����Ʈ���� ���� �÷���.
  * COM�� ���� ū Ư¡�� �ѹ� ���谡 �Ϸ�Ǹ� ������ �ʴ´ٴ� ������  
    �̴� COM�� ����ϴ� ���α׷��̳� COM�� �����ϴ� ���α׷��� ���� �ٸ� ������  
    ����ϴ��� �������� ������ �� �ֵ��� �Ѵ�.
  * COM�� GUID�� �̿��Ͽ� ��ü�� �ĺ��ϱ� ������ ���� �̸��� Ŭ������ ��밡���ϴ�.
</br></br>

* ## DoubleBuffering
  * ��ũ�� ȭ�鿡 �ش��ϴ� ���� ���ۿ� ���� �������� ���͸� ������ ���� ȭ���� �����̴� ������ �߻��Ѵ�.  
  �׷��� ���� ���ۿ� �������� ���� �ʰ� ������ ����� ��׶��� ���ۿ� ������ ��  
  ���۸� ����(bliting)�ϰų� ���� �����͸� ��ü(page flipping)�ϴ� ����� ����Ѵ�.
  </br></br>

* ## COM_Ptr
  * window runtime lib�� C++�� shader pointer�� ����� ptr  
  * GetAddressOf()�� �̿��� ���� �ּҸ� ���  
    Get()�� ���� ��ü�� �����Ѵ�.