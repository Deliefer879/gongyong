#include <stdio.h>

#define ARR_LEN 10

int main()
{
	int i, j;
	int insertData;

	int arr[ARR_LEN];

	for (i = 0; i < ARR_LEN; i++)
		arr[i] = 10 - i;

	for (i = 1; i < ARR_LEN; i++)
	{
		insertData = arr[i];

		for (j = i-1 ; j >=0; j--)
		{
			if (arr[j] > insertData)
				arr[j + 1] = arr[j];//���� �����Ͱ� �� Ŭ��� �����͸� 1ĭ �ڷ� �̵�
			else//�ݺ� ��ġ�� �߰� ������ Ż��
				break;
		}
		arr[j+1] = insertData;// �ݺ� ��ġ�� �߰��ϸ鼭 1������ j���� �ٽ� �����ϰ� ������ ����
	}
		
	for (i = 0; i < ARR_LEN; i++)
		printf("%d ", arr[i]);
	
	
	return 0;
}