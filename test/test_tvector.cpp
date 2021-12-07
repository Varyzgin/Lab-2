#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(4);
	v1[0] = 5, v1[1] = 10, v1[2] = 15, v1[3] = 20;
	TVector<int> v2 = v1;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(4);
	v1[0] = v1[1] = v1[2] = v1[3] = 1;
	TVector<int> v2 = v1;
	v2[0] = v2[1] = v2[2] = v2[3] = 2;
	for (int i = 0; i < 4; i++)
		ASSERT_TRUE((v1[i] == 1) && (v2[i] == 2));
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);
	ASSERT_TRUE(v.GetSize() == 4);
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);
	ASSERT_TRUE(v.GetStartIndex() == 2);
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	ASSERT_NO_THROW(v[0] = 4);
	ASSERT_TRUE(v[0] == 4);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1] = 5);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[4] = 100);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	v[0] = v[1] = v[2] = v[3] = 10;
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(4), v2(4);
	v1[0] = v1[1] = v1[2] = v1[3] = 10;
	ASSERT_NO_THROW(v2 = v1);
	ASSERT_TRUE(v2 == v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(4), v2(5);
	v2 = v1;
	ASSERT_TRUE(v2.GetSize() == 4);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(5), v2(4);
	v1[0] = v1[1] = v1[2] = v1[3] = v1[4] = 10;
	v2 = v1;
	TVector<int> res(5);
	res[0] = res[1] = res[2] = res[3] = res[4] = 10;
	ASSERT_TRUE(v2 == res);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(4, 0), v2(4, 0);
	v1[0] = 0, v1[1] = 1, v1[2] = 2, v1[3] = 3;
	v2[0] = 0, v2[1] = 1, v2[2] = 2, v2[3] = 3;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	v[0] = v[1] = v[2] = v[3] = 10;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(4), v2(5);
	for (int i = 0; i < 3; i++) {
		v1[i] = 10;
	}
	v2[4] = 10;
	ASSERT_TRUE(v1 != v2);
	ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	v[0] = 0, v[1] = 1, v[2] = 2, v[3] = 3;
	int i = 40;
	TVector<int> v1(4);
	v1[0] = 40, v1[1] = 41, v1[2] = 42, v1[3] = 43;
	ASSERT_TRUE(v + i == v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	v[0] = 40, v[1] = 41, v[2] = 42, v[3] = 43;
	int i = 40;
	TVector<int> v1(4);
	v1[0] = 0, v1[1] = 1, v1[2] = 2, v1[3] = 3;
	ASSERT_TRUE(v - i == v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4);
	v[0] = 0, v[1] = 1, v[2] = 2, v[3] = 3;
	int i = 40;
	TVector<int> v1(4);
	v1[0] = 0, v1[1] = 40, v1[2] = 80, v1[3] = 120;
	ASSERT_TRUE(v * i == v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(4), v2(4);
	v1[0] = 1, v1[1] = 2, v1[2] = 3, v1[3] = 4;
	v2[0] = 2, v2[1] = 3, v2[2] = 4, v2[3] = 5;
	TVector<int> res = v1 + v2;
	TVector<int> res1(4);
	res1[0] = 3, res1[1] = 5, res1[2] = 7, res1[3] = 9;
	ASSERT_TRUE(res == res1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5);
	v1[0] = 1, v1[1] = 2, v1[2] = 3, v1[3] = 4;
	v2[0] = 2, v2[1] = 3, v2[2] = 4, v2[3] = 5, v2[4] = 100;
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(4), v2(4);
	v1[0] = 1, v1[1] = 2, v1[2] = 3, v1[3] = 4;
	v2[0] = 2, v2[1] = 3, v2[2] = 4, v2[3] = 5;
	TVector<int> res;
	res = v1 - v2;
	TVector<int> res1 = v2 - v1;
	res1[0] = 1; res1[1] = 1; res1[2] = 1; res1[3] = 1;
	ASSERT_TRUE(res == res1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5);
	v1[0] = 1, v1[1] = 2, v1[2] = 3, v1[3] = 4;
	v2[0] = 2, v2[1] = 3, v2[2] = 4, v2[3] = 5, v2[4] = 100;
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(2), v2(2);
	v1[0] = 1, v1[1] = 3;
	v2[0] = 2, v2[1] = 4;
	const int res = v1 * v2;
	ASSERT_TRUE(res == 14);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5);
	v1[0] = 1, v1[1] = 2, v1[2] = 3, v1[3] = 4;
	v2[0] = 2, v2[1] = 3, v2[2] = 4, v2[3] = 5, v2[4] = 100;
	ASSERT_ANY_THROW(v1 * v2);
}