/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *canSeePersonsCount(int *heights, int heightsSize, int *returnSize)
{
    *returnSize = heightsSize;
    int i, j, k;
    for (i = 1; i < heightsSize; i++)
    {
        int count = 1, maxheight = heights[i];
        for (j = i + 1; j < heightsSize; j++)
        {
            if (heights[j] > maxheight)
            {
                count += 1;
                maxheight = heights[j];
            }
        }
        heights[i - 1] = count;
    }
    heights[heightsSize - 1] = 0;
    return heights;
}
