int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len)
{
        int arr3[101];

        for (int i = 0; i < 100; i++)
        {
                arr3[i] = 0;
        }

        if (len != 0)
        {
                for (unsigned int i = 0; i < len; i++)
                {
                        arr3[arr1[i]]++;
                        arr3[arr2[i]]--;
                }

                for (unsigned int i = 0; i < 100; i++)
                {
                        if (arr3[i] != 0)
                        {
                                return 0;
                        }
                }
                return 1;
        }
        else
        {
                return 1;
        }
}
