import React from 'react';

const Product = ({ item }) => {
  const imageUrl = item.images?.main;
  const oldPrice = item.old_price || 0;
  const discountValue = oldPrice > item.price ? oldPrice - item.price : 0;
  const status = item.sell_status || 'n/a';

  return (
    <article className="product-card">
      <div className="product-image-wrap">
        {imageUrl ? (
          <img src={imageUrl} alt={item.brand || 'Product'} loading="lazy" />
        ) : (
          <div className="product-placeholder">No image</div>
        )}
      </div>

      <div className="product-body">
        <p className="product-brand">{item.brand || 'Unknown brand'}</p>
        <h3>{item.title || `Product #${item.id}`}</h3>

        <div className="product-meta">
          <span className="price">{item.price} UAH</span>
          {oldPrice > 0 ? <span className="old-price">{oldPrice} UAH</span> : null}
        </div>

        <div className="product-meta">
          <span>ID: {item.id}</span>
          <span>Status: {status}</span>
        </div>

        {discountValue > 0 ? <p className="discount">Save: {discountValue} UAH</p> : null}

        {item.href ? (
          <a href={item.href} target="_blank" rel="noreferrer" className="product-link">
            Open product page
          </a>
        ) : null}
      </div>
    </article>
  );
};

export default Product;
