import React from 'react';
import './PricingCard.css';

const PricingCard = ({ title, price, color, features, isFeatured = false, isDark }) => {
  return (
    <article className={`pricing-card ${isFeatured ? 'featured' : ''} ${isDark ? 'dark' : 'light'}`}>
      <div className="card-header" style={{ backgroundColor: color }}>
        <h2>{title}</h2>
        <div className="price-badge">${price}</div>
      </div>

      <div className="card-body">
        <ul className="feature-list">
          {features.map((item, index) => (
            <li key={`${title}-${index}`} className={item.included ? 'included' : 'excluded'}>
              <span className={`icon ${item.included ? 'icon-included' : 'icon-excluded'}`}>
                {item.included ? '+' : '-'}
              </span>
              {item.text}
            </li>
          ))}
        </ul>
      </div>

      <div className="card-footer">
        <button className="select-btn" type="button" style={{ backgroundColor: color }}>
          Select plan
        </button>
      </div>
    </article>
  );
};

export default PricingCard;
