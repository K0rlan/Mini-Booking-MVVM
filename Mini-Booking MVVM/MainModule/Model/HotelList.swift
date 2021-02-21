//
//  HotelList.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import Foundation

enum HotelList {
    case initial
    case loading
    case success([Data])
    case failure(Error)
    
    struct Data: Decodable{
        let id: Int
        let name: String
        let address: String
        let stars: Double
        let distance: Double
        let suites_availability: String
    }
}



