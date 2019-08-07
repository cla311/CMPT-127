void reverse(int arr[], unsigned int len)
{
    int copy[len];
    for (unsigned int i = 0; i < len; i++)
    {
        copy[i] = arr[i];
    }

    int index = len - 1;
    for (unsigned int i = 0; i < len; i++)
    {
        arr[i] = copy[index];
        if (index >= 0)
        {
            index--;
        }
    }
}
