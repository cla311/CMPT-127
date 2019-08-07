int identical(int arr1[], int arr2[], unsigned int len)
{
    int count = 0;

    if (len != 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr1[i] == arr2[i])
            {
                count++;
                if (count == len)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}