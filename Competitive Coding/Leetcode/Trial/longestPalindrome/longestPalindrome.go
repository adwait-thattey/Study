package LongestPalindrome

import (
	"fmt"
)

func longestOddPal(s string) string {

	maxOffset := 0
	maxCenter := 0
	maxLen := 0
	fmt.Println(s)
	for center := 0; center < len(s); center++ {
		for offset := 0; center-offset >= 0 && center+offset < len(s); offset++ {

			if s[center-offset] != s[center+offset] {
				break
			}

			if 2*offset+1 > maxLen {
				maxOffset = offset
				maxCenter = center
				maxLen = 2*offset + 1
			}
		}

	}

	if maxLen > 0 {
		return s[maxCenter-maxOffset : maxCenter+maxOffset+1]
	} else {
		return ""
	}
}

func longestEvenPal(s string) string {

	maxLeft, maxRight := 0, 0
	maxLen := 0
	fmt.Println(s)
	for start := 0; start < len(s); start++ {
		for left, right := start, start+1; left >= 0 && right < len(s); left, right = left-1, right+1 {

			if s[left] != s[right] {
				break
			}

			if right-left+1 > maxLen {
				maxLeft, maxRight = left, right
				maxLen = right - left + 1
			}
		}

	}

	if maxLen > 0 {
		return s[maxLeft : maxRight+1]
	} else {
		return ""
	}
}
func LongestPalindrome(s string) string {

	longestEven, longestOdd := longestEvenPal(s), longestOddPal(s)

	if len(longestEven) > len(longestOdd) {
		return longestEven
	} else {
		return longestOdd
	}
}
