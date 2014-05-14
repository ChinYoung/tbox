/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author		ruki
 * @file		hash.c
 *
 */
/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "hash.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * data hash implementation
 */
static tb_size_t tb_item_func_hash_data_func_0(tb_byte_t const* data, tb_size_t size)
{
	return tb_crc_encode(TB_CRC_MODE_32_IEEE_LE, 0, data, size);
}
static tb_size_t tb_item_func_hash_data_func_1(tb_byte_t const* data, tb_size_t size)
{
	// from stl string
	tb_size_t 			v = 2166136261;
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e) v = 16777619 * v ^ (tb_size_t)(*p++);
	return v;
}
static tb_size_t tb_item_func_hash_data_func_2(tb_byte_t const* data, tb_size_t size)
{
	// rs-hash
	tb_size_t 			v = 0;  
	tb_size_t 			b = 378551;  
	tb_size_t 			a = 63689;  
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e)
	{  
		v = v * a + (*p++);  
		a = a * b;  
	}  
	return v;
}
static tb_size_t tb_item_func_hash_data_func_3(tb_byte_t const* data, tb_size_t size)
{
	// bkdr-hash
	tb_size_t 			v = 0;  
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e) v = (v * 131313) + (*p++);  
	return v;
}
static tb_size_t tb_item_func_hash_data_func_4(tb_byte_t const* data, tb_size_t size)
{
	// fnv-hash
	tb_size_t 			v = 0;  
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e) 
	{
		v *= 0x811C9DC5;  
		v ^= (*p++);  
	}  
	return v;  
}
static tb_size_t tb_item_func_hash_data_func_5(tb_byte_t const* data, tb_size_t size)
{
	// ap-hash
	tb_size_t 			v = 0xAAAAAAAA;  
	tb_size_t 			i = 0;
	tb_byte_t const* 	p = data;
	for (i = 0; i < size; i++, p++) 
	{  
		v ^= (!(i & 1)) ? ((v << 7) ^ (*p) * (v >> 3)) : (~((v << 11) + (*p) ^ (v >> 5)));  
	}
	return v;  
}
static tb_size_t tb_item_func_hash_data_func_6(tb_byte_t const* data, tb_size_t size)
{
	// hflp-hash
	tb_size_t 	v = 0;  
	tb_size_t 	i = 0;  
	tb_byte_t* 	b = (tb_byte_t*)&v;  
	for (i = 0; i < size; i++) b[i & 3] ^= data[i];  
	return v; 
}
static tb_size_t tb_item_func_hash_data_func_7(tb_byte_t const* data, tb_size_t size)
{
	// sdbm-hash
	tb_size_t 			v = 0;  
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e) v = (*p++) + (v << 6) + (v << 16) - v;  
	return v;
}
static tb_size_t tb_item_func_hash_data_func_8(tb_byte_t const* data, tb_size_t size)
{
	// bp-hash
	tb_size_t 			v = 0;  
	tb_byte_t const* 	p = data;
	tb_byte_t const* 	e = data + size;
	while (p < e) v = v << 7 ^ (*p++);  
	return v;  
}
static tb_size_t tb_item_func_hash_data_func_9(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0; 
}
static tb_size_t tb_item_func_hash_data_func_10(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}
static tb_size_t tb_item_func_hash_data_func_11(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}
static tb_size_t tb_item_func_hash_data_func_12(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}
static tb_size_t tb_item_func_hash_data_func_13(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}
static tb_size_t tb_item_func_hash_data_func_14(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}
static tb_size_t tb_item_func_hash_data_func_15(tb_byte_t const* data, tb_size_t size)
{
	tb_trace_noimpl();
	return 0;
}

/* //////////////////////////////////////////////////////////////////////////////////////
 * uint32 hash implementation
 */
static tb_size_t tb_item_func_hash_uint32_func_0(tb_uint32_t value)
{
	return (((value >> 3) * 2654435761));
}
static tb_size_t tb_item_func_hash_uint32_func_1(tb_uint32_t value)
{
	// Tomas Wang
	value = ~value + (value << 15);
	value = value ^ (value >> 12); 
	value = value + (value << 2); 
	value = value ^ (value >> 4); 
	value = value * 2057;
	value = value ^ (value >> 16); 
	return value;
}
static tb_size_t tb_item_func_hash_uint32_func_2(tb_uint32_t value)
{
	// Bob Jenkins' 32 bit integer hash function
	value = (value + 0x7ed55d16) + (value << 12); 
	value = (value ^ 0xc761c23c) ^ (value >> 19); 
	value = (value + 0x165667b1) + (value << 5); 
	value = (value + 0xd3a2646c) ^ (value << 9); 
	value = (value + 0xfd7046c5) + (value << 3);
	value = (value ^ 0xb55a4f09) ^ (value >> 16);  
	return value;
}
static tb_size_t tb_item_func_hash_uint32_func_3(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_0((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_4(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_1((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_5(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_2((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_6(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_3((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_7(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_4((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_8(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_5((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_9(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_6((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_10(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_7((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_11(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_8((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_12(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_9((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_13(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_10((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_14(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_11((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}
static tb_size_t tb_item_func_hash_uint32_func_15(tb_uint32_t value)
{
	return tb_item_func_hash_data_func_12((tb_byte_t const*)&value, sizeof(tb_uint32_t));
}

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
tb_size_t tb_item_func_hash_uint8(tb_uint8_t value, tb_size_t mask, tb_size_t index)
{
	// TODO: need optimization
	tb_uint32_t v = (tb_uint32_t)value;
	return tb_item_func_hash_uint32(v | (v << 8) | (v << 16) | (v << 24), mask, index);
}
tb_size_t tb_item_func_hash_uint16(tb_uint16_t value, tb_size_t mask, tb_size_t index)
{
	// TODO: need optimization
	tb_uint32_t v = (tb_uint32_t)value;
	return tb_item_func_hash_uint32(v | (v << 16), mask, index);
}
tb_size_t tb_item_func_hash_uint32(tb_uint32_t value, tb_size_t mask, tb_size_t index)
{
	// check
	tb_assert_and_check_return_val(mask, 0);

	// the func
	static tb_size_t (*s_func[])(tb_uint32_t) = 
	{
		tb_item_func_hash_uint32_func_0
	,	tb_item_func_hash_uint32_func_1
	,	tb_item_func_hash_uint32_func_2
	,	tb_item_func_hash_uint32_func_3
	,	tb_item_func_hash_uint32_func_4
	,	tb_item_func_hash_uint32_func_5
	,	tb_item_func_hash_uint32_func_6
	,	tb_item_func_hash_uint32_func_7
	,	tb_item_func_hash_uint32_func_8
	,	tb_item_func_hash_uint32_func_9
	,	tb_item_func_hash_uint32_func_10
	,	tb_item_func_hash_uint32_func_11
	,	tb_item_func_hash_uint32_func_12
	,	tb_item_func_hash_uint32_func_13
	,	tb_item_func_hash_uint32_func_14
	,	tb_item_func_hash_uint32_func_15
	};
	tb_assert_and_check_return_val(index < tb_arrayn(s_func), 0);

	// done
	return s_func[index](value) & mask;
}
tb_size_t tb_item_func_hash_uint64(tb_uint64_t value, tb_size_t mask, tb_size_t index)
{
	tb_size_t hash0 = tb_item_func_hash_uint32((tb_uint32_t)value, mask, index);
	tb_size_t hash1 = tb_item_func_hash_uint32((tb_uint32_t)(value >> 32), mask, index);
	return ((hash0 ^ hash1) & mask);
}
tb_size_t tb_item_func_hash_data(tb_byte_t const* data, tb_size_t size, tb_size_t mask, tb_size_t index)
{
	// check
	tb_assert_and_check_return_val(data && size && mask, 0);

	// the func
	static tb_size_t (*s_func[])(tb_byte_t const* , tb_size_t) = 
	{
		tb_item_func_hash_data_func_0
	,	tb_item_func_hash_data_func_1
	,	tb_item_func_hash_data_func_2
	,	tb_item_func_hash_data_func_3
	,	tb_item_func_hash_data_func_4
	,	tb_item_func_hash_data_func_5
	,	tb_item_func_hash_data_func_6
	,	tb_item_func_hash_data_func_7
	,	tb_item_func_hash_data_func_8
	,	tb_item_func_hash_data_func_9
	,	tb_item_func_hash_data_func_10
	,	tb_item_func_hash_data_func_11
	,	tb_item_func_hash_data_func_12
	,	tb_item_func_hash_data_func_13
	,	tb_item_func_hash_data_func_14
	,	tb_item_func_hash_data_func_15
	};
	tb_assert_and_check_return_val(index < tb_arrayn(s_func), 0);

	// done
	return s_func[index](data, size) & mask;
}
tb_size_t tb_item_func_hash_cstr(tb_char_t const* cstr, tb_size_t mask, tb_size_t index)
{
	// check
	tb_assert_and_check_return_val(cstr && mask, 0);

	// TODO: need optimization
	return tb_item_func_hash_data((tb_byte_t const*)cstr, tb_strlen(cstr), mask, index);
}