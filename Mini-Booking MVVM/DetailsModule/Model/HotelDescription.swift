//
//  HotelDescription.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import Foundation
import UIKit

enum HotelDescription {
    case initial
    case loading
    case success(Data)
    case failure(Error)
    
    struct Data: Codable{
        let id: Int
        let name: String
        let address: String
        let stars: Double
        let distance: Double
        let suites_availability: String
        let image: String?
        let lat: Double
        let lon: Double
    }
}

class HotelImage {
    static let sharedInstance = HotelImage()
    var image = UIImage()
}
