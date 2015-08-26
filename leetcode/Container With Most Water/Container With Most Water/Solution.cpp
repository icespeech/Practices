#include "Solution.h"

int Solution::maxArea(std::vector<int>& height)
{
    if (height.size() < 2) return 0;
    
    int lb = 0, rb = height.size() - 1;
    int currentArea = 0;

    while (lb < rb)
    {
        int tmpArea;
        if (height[lb] < height[rb])
        {
            tmpArea = (rb - lb)*height[lb];
            if (tmpArea > currentArea)
                currentArea = tmpArea;
            ++lb;
        }
        else if (height[lb] > height[rb])
        {
            tmpArea = (rb - lb)*height[rb];
            if (tmpArea > currentArea)
                currentArea = tmpArea;
            --rb;
        }
        else
        {
            tmpArea = (rb - lb)*height[lb];
            if (tmpArea > currentArea)
                currentArea = tmpArea;

            int tlb = lb + 1, trb = rb -1 ;
            while (tlb < rb && height[tlb] <= height[lb]) ++tlb;
            // the elements between lb and rb are all shorter than height[rb] (i.e. height[lb])
            if (tlb == rb) break;

            while (trb > lb && height[trb] <= height[rb]) --trb;

            int tmpAreaLeft = (rb - tlb)*(height[rb]);
            int tmpAreaRight = (trb - lb)*(height[lb]);

            if (tmpAreaLeft > tmpAreaRight)
            {
                if (tmpAreaLeft > currentArea)
                    currentArea = tmpAreaLeft;
                lb = tlb;
            }
            else
            {
                if (tmpAreaRight > currentArea)
                    currentArea = tmpAreaRight;
                rb = trb;
            }
        }
    }
    return currentArea;
}