/*
 * OcgMessage.hpp
 *
 *  Created on: Jul 18, 2015
 *      Author: felix
 */

#ifndef OCGMESSAGE_HPP_
#define OCGMESSAGE_HPP_

#define BODY_FIELDS_MAP \
	static const field_attribute body_fields_map[];

#define BODY_FIELDS_MAP_INIT_BEGIN(TYPE) \
	TYPE TYPE##_t; \
	const field_attribute TYPE::body_fields_map[] { \

#define BODY_FIELDS_MAP_INIT_ADD_FIELD(TYPE, FIELD) \
	{(UInt32)sizeof(TYPE), (UInt32)((unsigned char*)&TYPE##_t.FIELD - (unsigned char*)&TYPE##_t)},

#define BODY_FIELDS_MAP_INIT_END \
	};

////////////////////////////////////////
// Header & Trailer Field Data Dictionary
////////////////////////////////////////

#define BODY_FIELDS_PRESENCE_MAP	unsigned char	body_fields_presence_map[32];
#define CHECKSUM					UInt32			checksum;
#define COMP_ID						unsigned char	comp_id[12];
#define LENGTH						UInt16			length;
#define MESSAGE_TYPE				UInt8			message_type;
#define POSS_DUP					UInt8			poss_dup;
#define POSS_RESEND					UInt8			poss_resend;
#define SEQUENCE_NUMBER				UInt32			sequence_number;
#define START_OF_MESSAGE			UInt8			start_of_message;

////////////////////////////////////////
// Body Field Data Dictionary
////////////////////////////////////////

#define AMEND_REJECT_CODE				UInt16			amend_reject_code;
#define BROKER_ID						unsigned char	broker_id[12];
#define BROKER_LOCATION_ID				unsigned char	broker_location_id[11];
#define BUSINESS_REJECT_CODE			UInt16			business_reject_code;
#define BUSINESS_REJECT_REFERENCE_ID	unsigned char	business_reject_reference_id[21];
#define BID_SIZE						Decimal			bid_size;
#define BID_PRICE						Decimal			bid_price;
#define CANCEL_REJECT_CODE				UInt16			cancel_reject_code;
#define CLEARING_INSTRUCTION			UInt8			clearing_instruction;
#define CLIENT_ORDER_ID					unsigned char	client_order_id[21];
#define COUNTER_PARTY_BROKER_ID			unsigned char	client_order_id[12];
#define CUMULATIVE_QUANTITY				Decimal			cumulative_quantity;
#define DISCLOSURE_INSTRUCTIONS			UInt16			disclosure_instructions;
#define END_SEQUENCE					UInt32			end_sequence;
#define ENTITLEMENT_ATTRIBUTE_TYPE		UInt16			entitlement_attribute_type;
#define ENTITLEMENT_ATTRIBUTE_DATA_TYPE	UInt16			entitlement_attribute_data_type;
#define ENTITLEMENT_ATTRIBUTE_VALUE		unsigned char	entitlement_attribute_value[21];
#define ENTITLEMENT_ID					unsigned char	entitlement_id[21];
#define ENTITLEMENT_INDICATOR			UInt8			entitlement_indicator;
#define ENTITLEMENT_REQUEST_ID			unsigned char	entitlement_request_id[21];
#define ENTITLEMENT_REPORT_ID			unsigned char	entitlement_report_id[21];
#define ENTITLEMENT_TYPE				UInt8			entitlement_type;
#define EXEC_TYPE						Byte			exec_type;
#define EXECUTION_ID					unsigned char	execution_id[21];
#define EXECUTION_PRICE					Decimal			execution_price;
#define EXECUTION_QUANTITY				Decimal			execution_quantity;
#define	EXECUTION_INSTRUCTIONS			unsigned char	execution_instructions[21];
#define EXEC_RESTATEMENT_REASON			UInt16			exec_restatement_reason;
#define EXCHANGE_TRADE_TYPE				Byte			exchange_trade_type;
#define	GAP_FILL						Byte			gap_fill;
#define INSTRUMENT_SCOPE_OPERATOR		UInt8			instrument_scope_operator;
#define LAST_FRAGMENT					UInt8			last_fragment;
#define LEAVES_QUANTITY					Decimal			leaves_quantity;

#define LOOKUP_REJECT_CODE				UInt8			lookup_reject_code;

#define PROTOCOL_TYPE					UInt8			protocol_type;
#define PRIMARY_IP						unsigned char	primary_ip[16];
#define PRIMARY_PORT					UInt16			primary_port;

#define REASON							UInt16			reason_length; \
														unsigned char	reason[75 - sizeof(UInt16)];

#define SECONDARY_IP					unsigned char	secondary_ip[16];
#define SECONDARY_PORT					UInt16			secondary_port;
#define SESSION_STATUS					UInt8			session_status;

#define STATUS							UInt8			status;

#define TYPE_OF_SERVICE					UInt8			type_of_service;

namespace meteor {
	namespace ocg {
		typedef unsigned char Byte;
		typedef long long Decimal;
		typedef unsigned char UInt8;
		typedef char Int8;
		typedef unsigned short UInt16;
		typedef short Int16;
		typedef unsigned int UInt32;
		typedef int Int32;
		typedef unsigned long long UInt64;
		typedef long long Int64;

		struct field_attribute {
			UInt32 field_size;
			UInt32 field_offset;
		};

		////////////////////////////////////////
		// Message Header & Trailer
		////////////////////////////////////////

		struct message_header {
			START_OF_MESSAGE LENGTH
			;MESSAGE_TYPE
			;SEQUENCE_NUMBER
			;POSS_DUP
			;POSS_RESEND
			;COMP_ID
			;BODY_FIELDS_PRESENCE_MAP
			;
		}__attribute((aligned(4)));

		struct message_trailer {
			CHECKSUM
			;
		}__attribute((aligned(4)));

		////////////////////////////////////////
		// Lookup Service
		////////////////////////////////////////

		struct lookup_request {
			BODY_FIELDS_MAP

			TYPE_OF_SERVICE
			;PROTOCOL_TYPE
			;
		}__attribute((aligned(4)));

		struct lookup_response {
			BODY_FIELDS_MAP

			STATUS
			;LOOKUP_REJECT_CODE
			;REASON
			;PRIMARY_IP
			;PRIMARY_PORT
			;SECONDARY_IP
			;SECONDARY_PORT
			;
		}__attribute((aligned(4)));

		////////////////////////////////////////
		// Administrative Messages
		////////////////////////////////////////

		////////////////////////////////////////
		// Helper functions
		////////////////////////////////////////

		////////////////////////////////////////
		// Helper functions
		////////////////////////////////////////

		void verify_message_size();
	}
}

#endif /* OCGMESSAGE_HPP_ */
