pragma experimental SMTChecker;

contract C
{
	mapping (uint => uint) a;
	function f(mapping (uint => uint) storage map1, mapping (uint => uint) storage map2) internal {
		require(map1[0] == 2);
		require(a[0] == 42);
		map2[0] = 1;
		// Fails because map2 == map1 is possible.
		assert(map1[0] == 2);
		// Fails because map2 == a is possible.
		assert(a[0] == 42);
		assert(map2[0] == 1);
	}
}
// ----
// Warning: (280-300): Assertion violation happens here
// Warning: (346-364): Assertion violation happens here
