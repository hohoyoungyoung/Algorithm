import math

def solution(fees, records):
    basic_time, basic_fee, unit_time, unit_fee = fees
    
    # 차 번호별 주차 시간과 입출차 기록을 저장할 딕셔너리
    parking_records = {}
    total_time = {}

    for record in records:
        time, car_number, status = record.split()
        
        if car_number not in parking_records:
            parking_records[car_number] = [time, status]
            total_time[car_number] = 0
        elif status == 'IN':
            parking_records[car_number] = [time, status]
        else:
            in_time = parking_records[car_number][0]
            out_time = time
            
            in_minutes = int(in_time[:2]) * 60 + int(in_time[3:])
            out_minutes = int(out_time[:2]) * 60 + int(out_time[3:])
            
            duration = out_minutes - in_minutes
            total_time[car_number] += duration
            parking_records[car_number] = [time, status]

    for car_number in parking_records:
        if parking_records[car_number][1] == 'IN':
            in_time = parking_records[car_number][0]
            in_minutes = int(in_time[:2]) * 60 + int(in_time[3:])
            out_minutes = 23 * 60 + 59  # 23:59로 계산
            
            duration = out_minutes - in_minutes
            total_time[car_number] += duration

    for car_number in total_time:
        if total_time[car_number] <= basic_time:
            total_time[car_number] = basic_fee
        else:
            total_time[car_number] = basic_fee + math.ceil((total_time[car_number] - basic_time) / unit_time) * unit_fee

    sorted_car_numbers = sorted(total_time.keys())
    answer = [total_time[car_number] for car_number in sorted_car_numbers]

    return answer
