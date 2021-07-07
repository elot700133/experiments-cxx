//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// basic operations
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//=======================================
// insert at beginning of array
for (int i = intArray.size()-2; i >= 0; i--) {   // -2 because last index is -1, -2 is previous index before last index
    intArray[i + 1] = intArray[i];
}

// Now that we have created space for the new element,
// we can insert it at the beginning.
intArray[0] = 20;

//=========================================
// insert at anywhere
// Say we want to insert the element at index 2.
// First, we will have to create space for the new element.
for (int i = intArray.size()-2; i >= 2; i--)
{
    // Shift each element one position to the right.
    intArray[i + 1] = intArray[i];
}

// Now that we have created space for the new element,
// we can insert it at the required index.
intArray[2] = 30;

//===========================================
// make it a generic function
void insert(int index, int value, vector<int>& arr) {
	for(int i=arr.size()-2; i>=index; --i) {
	    arr[i+1] = arr[i];
	}
	arr[index] = value;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// questions
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//=============================================
// duplicate zeros
//Input: [1,0,2,3,0,4,5,0]
//Output: null
//Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0; i<arr.size(); ++i) {
            if ( arr[i] == 0) {
                insert(i,0,arr);
                ++i;
            }
        }
    }
    
    void insert(int index, int value, vector<int>& arr) {
        for(int i=arr.size()-2; i>=index; --i) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
    }
};

//=====================================================
// merge sorted array
//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and
// two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//
//The final sorted array should not be returned by the function, but instead be stored inside
//the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements
//denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
//The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// solution from discussion board
// key is to iterate from the back
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1; // last index of A
		int j=n-1; // last index of B
		int k = m+n-1; // last index of new array (which is using A as storage)
		while(i >=0 && j>=0)
		{
			if(A[i] > B[j])
				A[k--] = A[i--];
			else
				A[k--] = B[j--];
		}
		while(j>=0)
			A[k--] = B[j--];
    }
};

// my first solution
// this iterate from front
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int> ans(m+n);
        int k=0;
        while(j<n || i<m) {
            if ( i<m && j<n && nums1[i] < nums2[j] ) {
                ans[k++] = nums1[i];
                i++;
            }
            else if ( j<n ) {
                ans[k++] = nums2[j];
                j++;
            }
            else if ( i<m) {
                ans[k++] = nums1[i];
                i++;
            }
        }
        nums1 = ans; // copy is bad!
    }
};

