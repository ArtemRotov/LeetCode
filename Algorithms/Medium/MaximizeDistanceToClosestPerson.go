/*
849. Maximize Distance to Closest Person

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/

func maxDistToClosest(seats []int) int {
    left := -1
    cnt := 0
    maximum := 0
    for i:= 0; i < len(seats); i++ {
        if seats[i] == 0 {
            cnt++
            continue
        } else {
            if cnt > 0 && left == -1 {

            } else {
                cnt = ((cnt - 1) / 2) + 1
            }

            maximum = max(cnt, maximum)
            left = i
            cnt = 0
        }
    }
    if cnt > 0 {
        maximum = max(cnt, maximum)
    }

    return maximum
}

func max(a,b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

    
