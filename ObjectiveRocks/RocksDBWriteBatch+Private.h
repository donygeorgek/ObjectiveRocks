//
//  RocksDBWriteBatch+Private.h
//  ObjectiveRocks
//
//  Created by Iska on 11/01/15.
//  Copyright (c) 2015 BrainCookie. All rights reserved.
//

#import "RocksDBWriteBatch.h"
#import "RocksDBIndexedWriteBatch.h"

namespace rocksdb {
	class ColumnFamilyHandle;
	class WriteBatchBase;
}

/**
 This category is intended to hide all C++ types from the public interface in order to
 maintain a pure Objective-C API for Swift compatibility.
 */
@interface RocksDBWriteBatch (Private)

/** @brief The rocksdb::WriteBatchBase associated with this instance. */
@property (nonatomic, readonly) rocksdb::WriteBatchBase *writeBatchBase;

/**
 Initializes a new instance of `RocksDBWriteBatch` with the given native rocksdb::WriteBatchBase 
 instance, encoding options and rocksdb::ColumnFamilyHandle instance.

 @discussion This initializer is used by the subclasses of `RocksDBWriteBatch`.

 @param writeBatchBase An instance of a concrete subclass implementation of rocksdb::WriteBatchBase.
 @param columnFamily The rocks::ColumnFamilyHandle instance.
 @param options The Encoding options.
 @return a newly-initialized instance of `RocksDBWriteBatch`.

 @see RocksDBEncodingOptions
 */
- (instancetype)initWithNativeWriteBatch:(rocksdb::WriteBatchBase *)writeBatchBase
							columnFamily:(rocksdb::ColumnFamilyHandle *)columnFamily
					  andEncodingOptions:(RocksDBEncodingOptions *)options;

/**
 Initializes a new instance of a simple `RocksDBWriteBatch` with the given options and
 rocksdb::ColumnFamilyHandle instance.

 @param columnFamily The rocks::ColumnFamilyHandle instance.
 @param options The Encoding options.
 @return a newly-initialized instance of `RocksDBWriteBatch`.

 @see RocksDBEncodingOptions
 */
- (instancetype)initWithColumnFamily:(rocksdb::ColumnFamilyHandle *)columnFamily
				  andEncodingOptions:(RocksDBEncodingOptions *)options;

@end

/**
 This category is intended to hide all C++ types from the public interface in order to
 maintain a pure Objective-C API for Swift compatibility.
 */
@interface RocksDBIndexedWriteBatch (Private)

/**
 Initializes a new instance of `RocksDBIndexedWriteBatch` with the given options and
 rocksdb::ColumnFamilyHandle instance.

 @discussion `RocksDBIndexedWriteBatch` builds a binary searchable index for all 
 the keys inserted.

 @param columnFamily The rocks::ColumnFamilyHandle instance.
 @param options The Encoding options.
 @return a newly-initialized instance of `RocksDBWriteBatch`.

 @see RocksDBEncodingOptions
 */
- (instancetype)initWithColumnFamily:(rocksdb::ColumnFamilyHandle *)columnFamily
				  andEncodingOptions:(RocksDBEncodingOptions *)options;

@end
